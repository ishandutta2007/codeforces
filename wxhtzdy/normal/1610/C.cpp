#include <bits/stdc++.h>
using namespace std;
int main()
{
int tt;
scanf("%i",&tt);
while(tt--)
{
int n;
scanf("%i",&n);
int a[n],b[n];
for(int i=0;i<n;i++)scanf("%i%i",&a[i],&b[i]);
int l=0,r=n,ans;
while(l<=r)
{
int mid=l+r>>1;
int cnt=0;
for(int i=n-1;i>=0;i--)
{
if(a[i]>=cnt&&b[i]>=mid-cnt-1)cnt++;
}
if(cnt>=mid)ans=mid,l=mid+1;
else r=mid-1;
}
printf("%i\n",ans);
}
}