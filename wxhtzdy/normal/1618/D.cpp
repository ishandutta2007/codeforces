#include <bits/stdc++.h>
using namespace std;
int main()
{
int tt;
cin>>tt;
while(tt--)
{
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
long long s=0;
for(int i=0;i<n;i++)s+=a[i];
for(int j=0;j<k;j++)
{
int l=n-j*2-1,r=l-1;
s-=a[l];
s-=a[r];
s+=a[n-j-k-1]/a[n-j-1];
}
cout<<s<<"\n";
}
}