#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;

in nar[4009];
in pf[4009];
in mp[40000];
int main(){
  in a;
  string s;
  cin>>a>>s;
  in m=s.length();
  for(in i=0;i<m;i++)
    nar[i]=s[i]-'0';
  pf[0]=0;
  for(in i=0;i<m;i++)
    pf[i+1]=pf[i]+nar[i];
  for(in i=0;i<=m;i++)
    for(in j=i+1;j<=m;j++)
      mp[pf[j]-pf[i]]++;
  in sm=0;
  if(a!=0){
    for(in i=0;i<=m;i++)
      for(in j=i+1;j<=m;j++)
	if(pf[j]-pf[i]!=0 && a%(pf[j]-pf[i])==0 && a/(pf[j]-pf[i])<40000)
	  sm+=mp[a/(pf[j]-pf[i])];
  }
  else{
    in tsm=(m+1)*m/2;
    in zrc=0;
    for(in i=0;i<=m;i++)
      for(in j=i+1;j<=m;j++)
	if(pf[j]-pf[i]==0)
	  zrc++;
    sm=zrc*tsm+zrc*tsm-zrc*zrc;
  }
  cout<<sm<<endl;
  return 0;
}