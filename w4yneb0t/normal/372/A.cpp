#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in n;
in a[500009];
int main(){
  cin>>n;
  for(in i=0;i<n;i++)
    cin>>a[i];
  sort(a,a+n);
  reverse(a,a+n);
  in i=0;
  in j=(n+1)/2;
  while(1){
    while(j<n && a[j]*2>a[i])
      j++;
    if(j<n){
      j++;
      i++;
    }
    if(j>=n || 2*i+1>=n)
      break;
  }
  cout<<n-i<<endl;
  return 0;
}