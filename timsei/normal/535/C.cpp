//long long 
#include<bits/stdc++.h>
using namespace std;
#define N 10000001
long long S[N];
long long l,t,m,a,n,b,ll;
long long ans;
bool pan(long long xx)
{
	if(((xx-1)*b+a)>t) return 0;
	long long dance=((xx-1)*b+a+(ll-1)*b+a)*(xx-ll+1)/2;
	long long it=m*t;
	if(dance<=it) return 1;else return 0;
}
int main()
{
	cin>>a>>b>>n;
	while(n--)
	{
		cin>>l>>t>>m;
		ans=-1;
		long long r=(l+(t-a)/b+100);
		ll=l;
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			if(pan(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
}