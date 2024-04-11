#include<bits/stdc++.h>
//
using namespace std;

int main()
{
  int n,t;
  cin>>n>>t;
  int a[n];
  for(int i=1;i<=n;i++)
    cin>>a[i];
  int i;
  for(i=1;i<t;i+=a[i]);
  if(i==t)
    cout<<"YES";
  else
    cout<<"NO";
}