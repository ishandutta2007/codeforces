#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%i",&n);
  map<string,int> m;
  m["polycarp"]=1;
  int sol=0;
  for(int i=0;i<n;i++){
    string a,useless,b;
    cin>>a>>useless>>b;
    for(int j=0;j<(int)a.length();j++)if(a[j]<'a')a[j]+='a'-'A';
    for(int j=0;j<(int)b.length();j++)if(b[j]<'a')b[j]+='a'-'A';
    m[a]=m[b]+1;sol=max(sol,m[a]);
  }
  printf("%i",sol);
}