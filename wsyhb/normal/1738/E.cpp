#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int max_R=2e5+5;
int fac[max_R],inv_fac[max_R],inv[max_R];
inline void init(int R)
{
	fac[0]=inv_fac[0]=1;
	fac[1]=inv_fac[1]=inv[1]=1;
	for(int i=2;i<=R;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%mod;
	}
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
const int max_n=1e5+5;
int a[max_n];
long long pref[max_n],suff[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		init(n<<1);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			pref[i]=pref[i-1]+a[i];
		}
		for(int i=n;i>=1;--i)
			suff[i]=suff[i+1]+a[i];
		int R=n,ans=0,res=1;
		bool flag_over=false;
		for(int l=1;l<=n;++l)
		{
			int r=l;
			while(r+1<=n&&pref[r+1]==pref[l])
				++r;
			while(R>0&&suff[R]<pref[l])
				--R;
//			fprintf(stderr,"l=%d r=%d R=%d\n",l,r,R);
			if(!R||suff[R]!=pref[l])
			{
				l=r;
				continue;
			}
			if(l>R-1)
				break;
			int L=R;
			while(L-1>=1&&suff[L-1]==suff[R])
				--L;
			if(r>=L-1)
			{
				flag_over=true;
				int now=0;
				for(int i=l;i<=r;++i)
				{
					int x=i-l,y=(R-1)-max(L-1,i)+1;
//					fprintf(stderr,"x=%d y=%d\n",x,y);
					now=(now+C(x+y,y-1))%mod;
				}
				ans=res*(now+1ll)%mod;
				break;
			}
			else
			{
				int x=r-l+1,y=R-L+1,now=0;
				for(int k=0;k<=min(x,y);++k)
					now=(now+1ll*C(x,k)*C(y,k))%mod;
				res=1ll*res*now%mod;
			}
			l=r;
		}
		if(!flag_over)
			ans=res;
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)
			pref[i]=suff[i]=0;
	}
	return 0;
}
/*
1
2
1 1
---
2
*/