#include<bits/stdc++.h>
#define ll long long
using namespace std;
int q;
ll a,b,m;
ll k;
ll xp[55];
ll R[55],v[55];
int main()
{
	scanf("%d",&q);
	for(int i=0;i<=50;++i)xp[i]=(1ll<<i);
	while(q--)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&m);
		if(a==b)
		{
			printf("1 %I64d\n",a);
			continue;
		}
		k=2;
		bool yes=0;
		while(k<=50)
		{
			ll sr=b-xp[k-2]*a;
			ll x=xp[k-2];
			if(sr<x)break;
			if(sr>m*x){k++;continue;}
			ll l=1,r=m,ans=1;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(mid*x<=sr)l=mid+1,ans=mid;
				else r=mid-1;
			}
			memset(R,0,sizeof(R));
			for(int i=2;i<=k;++i)R[i]=ans;
			sr-=ans*x;
			int p=2;
			for(int i=k-3;i>=0;--i)
			{
				if(sr>=xp[i])sr-=xp[i],R[p]++;
				++p;
			}
			yes=1;
			break;
		}
		if(!yes)
		{
			puts("-1");
		}
		else
		{
			memset(v,0,sizeof(v));
			v[1]=a;
			for(int i=2;i<=k;++i)
			{
				for(int j=1;j<i;++j)v[i]+=v[j];
				v[i]+=R[i];
			}
			printf("%I64d",k);
			for(int i=1;i<=k;++i)printf(" %I64d",v[i]);
			puts("");
		}
	}
}