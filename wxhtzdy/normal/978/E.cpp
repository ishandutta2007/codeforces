#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int a[n],sum=0,mn=0,mx=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    mn=min(mn,sum);
    mx=max(mx,sum);
  }
  cout<<max(0,(k-mx)-abs(mn)+1);
}