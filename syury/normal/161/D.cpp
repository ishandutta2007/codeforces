#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<utility>
#include<iostream>
#include<list>

using namespace std;
typedef long long int lint;

int n,k,cnt=0;
vector<vector<lint> >ans;
vector<vector<int> >gr;

void solve(lint v,lint p=-1){
  ans[v].resize(k+1);ans[v].assign(k+1,0);
  ans[v][0]=1;
  for (size_t i=0;i<gr[v].size();i++){
    if(gr[v][i]!=p){solve(gr[v][i],v);}
  }
  for (lint i=1;i<=k;i++){
    for (lint u=0;u<gr[v].size();u++){
      if(gr[v][u]!=p){
	ans[v][i]+=ans[gr[v][u]][i-1];
      }
    }
  }
  lint extra=0;
  for (lint u=0;u<gr[v].size();u++){
    if(gr[v][u]==p){continue;}
    lint to=gr[v][u];
    for (lint i=1;i<=k-1;i++){
      extra+=ans[to][i-1]*(ans[v][k-i]-ans[to][k-i-1]);
    }
  }
  cnt+=ans[v][k]+extra/2;
}

int main(){
  scanf("%d%d",&n,&k);
  gr.resize(n);ans.resize(n);
  for (lint i=0;i<n-1;i++){
    int v,u;
    scanf("%d%d",&v,&u);v--;u--;
    gr[v].push_back(u);gr[u].push_back(v);
  }
  solve(0);
  cout<<cnt;
  return 0;
}