#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#define mod 1000000007
#define int long long
#pragma GCC optimize 2
using namespace std;
int a[1000500],cnt[1000500];
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1) rtn*=x,rtn%=mod;
		x*=x,x%=mod,y>>=1;
	}
	return rtn;
}
set <int> s;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,p;
		cin >> n >> p;
		if(p==1)
		{
			for(int i=1;i<=n;i++)
				scanf("%lld",&p);
			printf("%lld\n",n&1);
			continue;
		}
		for(auto x:s) cnt[-x]=0;
		s.clear();
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]),cnt[a[i]]++,s.insert(-a[i]);
		int now=0,ans=0,lst=1e6,flag=0;
		for(auto x:s)
		{
			x=-x;
			if(flag)
			{
				while(lst>x&&now<=2e6)
					now*=p,lst--;
			}
			if(flag)
			{
				while(now&&cnt[x]) --now,--cnt[x],ans-=ksm(p,x);
				if(!now) flag=0;
			}
			if(flag==0&&cnt[x]%2==0) continue;
			if(flag==0&&cnt[x]%2==1)
				now=1,flag=1,ans+=ksm(p,x),lst=x;
			
		}
		printf("%lld\n",(ans%mod+mod)%mod);
	}
	return 0;
}