#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main() {
  int n,m;
  scanf("%i%i",&n,&m);
  char a[1010],b[1010];
  scanf("%s%s",&a,&b);
  int sz=n;
  vector<int> ans;
  for(int i=0;i<m-n+1;i++){
    vector<int> v;
    for(int j=0;j<n;j++)if(a[j]!=b[i+j])v.pb(j);
    int ns=(int)v.size();
    if(ns<=sz)sz=ns,ans=v;
  }
  printf("%i\n",sz);
  for(int i=0;i<sz;i++)printf("%i ",ans[i]+1);
}