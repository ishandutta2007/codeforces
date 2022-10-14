#include <bits/stdc++.h>
using namespace std;
int main()
{
int tt;
cin>>tt;
while(tt--)
{
int n;
cin>>n;
long long a[n];
for(int i=0;i<n;i++)cin>>a[i];
long long x=0,y=0;
for(int i=0;i<n;i++)
{
if(i%2==0)x=__gcd(x,a[i]);
else y=__gcd(y,a[i]);
}
bool ok1=1,ok2=1;
for(int i=0;i<n;i++)
{
if(i%2==0&&a[i]%y==0)ok1=0;
if(i%2==1&&a[i]%x==0)ok2=0;
}
if(ok2)cout<<x<<"\n";
else if(ok1)cout<<y<<"\n";
else cout<<0<<"\n";
}
}