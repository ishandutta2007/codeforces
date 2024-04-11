#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long in;
in n;
in pm[3009];
in iv=0;
int main(){
  cin>>n;
  for(in i=0;i<n;i++)
    cin>>pm[i];
  for(in i=0;i<n;i++)
    for(in j=i+1;j<n;j++)
      iv+=(pm[i]>pm[j]);
  if(iv%2==0)
    cout<<2*iv<<endl;
  else
    cout<<(2*iv-1)<<endl;
  return 0;
}