#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long a[n],b[n],sum=0;
  for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  sort(b,b+n);
  if(b[n-1]+b[n-2]>=sum)cout<<"YES";
  else cout<<"NO";
}