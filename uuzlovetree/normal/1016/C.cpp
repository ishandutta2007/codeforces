#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
using namespace std;
int n;
ll a[maxn],b[maxn];
ll pre1[maxn],suf1[maxn],pre2[maxn],suf2[maxn];
ll sl1[maxn],sl2[maxn],sr1[maxn],sr2[maxn];
ll ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%I64d",&b[i]);
	for(int i=1;i<=n;++i)pre1[i]=pre1[i-1]+a[i],pre2[i]=pre2[i-1]+b[i];
	for(int i=n;i;--i)suf1[i]=suf1[i+1]+a[i],suf2[i]=suf2[i+1]+b[i];
	ll t;
	t=0;
	for(int i=1;i<=n;++i)sl1[i]=sl1[i-1]+t*a[i],++t;
	t=0;
	for(int i=n;i;--i)sr1[i]=sr1[i+1]+t*a[i],++t;
	t=0;
	for(int i=1;i<=n;++i)sl2[i]=sl2[i-1]+t*b[i],++t;
	t=0;
	for(int i=n;i;--i)sr2[i]=sr2[i+1]+t*b[i],++t;
	ans=sl1[n]+sr2[1]+suf2[1]*n;
	ll tmp=0,k;
	for(int i=1;i<n;++i)
	{
		if(i&1)tmp+=a[i]*(2*i-2)+b[i]*(2*i-1);
		else tmp+=a[i]*(2*i-1)+b[i]*(2*i-2);
		sl1[n]-=a[i]*(i-1);
		sl2[n]-=b[i]*(i-1);
		if(i&1)
		{
			k=sl2[n]+suf2[i+1]*i+sr1[i+1]+suf1[i+1]*(n+i);
			ans=max(ans,k+tmp);
		}
		else
		{
			k=sl1[n]+suf1[i+1]*i+sr2[i+1]+suf2[i+1]*(n+i);
			ans=max(ans,k+tmp);
		}
		/*cerr<<tmp<<endl;
		cerr<<sl1[n]<<endl;
		cerr<<sl2[n]<<endl;*/
	}
	cout<<ans<<endl;
	return 0;
}