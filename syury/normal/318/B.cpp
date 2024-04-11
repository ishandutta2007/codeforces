#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

vector<int>a[2];
int n;

vector<int> pref(string p){
  int l=p.length();
  vector<int>pi(l);
  pi[0]=0;
  for (int i=1;i<l;i++){
    int j=pi[i-1];
    while((j>0)&&(p[i]!=p[j])){j=pi[j-1];}
    if(p[i]==p[j]){j++;}
    pi[i]=j;
  }
  return pi;
}

void kmp(string t,string p,int v){
  int lt=t.length(),lp=p.length();
  vector<int>pi=pref(p);
  int j=0;
  for (int i=0;i<lt;i++){
    while((j>0)&&(p[j]!=t[i])){j=pi[j-1];}
    if(p[j]==t[i]){j++;}
    if(j==lp){a[v].push_back(i-lp+1);j=pi[j-1];}
  }
}

int main(){
  string s;
  long long int ans=0;
  cin>>s;
  kmp(s,"heavy",0);
  kmp(s,"metal",1);
  int j=0;
  for (int i=0;i<a[0].size();i++){
    while((j<a[1].size())&&(a[1][j]<a[0][i])){j++;}
    ans+=a[1].size()-j;
  }
  cout<<ans<<endl;
  return 0;
}