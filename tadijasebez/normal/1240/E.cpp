#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ldb long double
const int mod=1e9+7;//998244353;
void ckmx(int &x, int y){ x=max(x,y);}
void ckmn(int &x, int y){ x=min(x,y);}
void ckmx(ll &x, ll y){ x=max(x,y);}
void ckmn(ll &x, ll y){ x=min(x,y);}
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
const int N=500050;
int n,a[N];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++) scanf("%i",&a[i]);
    sort(a+1,a+1+n);
    ll sol=0;
    for(int y=2;y<N;y++)
	{
		vector<pair<int,int>> intervals;
		int l=1;
		ll sum=0;
		for(int j=1;1;j++)
		{
			int r=lower_bound(a+1,a+1+n,y*j)-a-1;
			intervals.pb({l,r});
			sum+=(ll)(j-1)*(r-l+1);
			l=r+1;
			if(l==n+1) break;
		}
        int top=min(sum,(ll)N),bot=2,x,ans=-1;
        while(top>=bot)
		{
			x=top+bot>>1;
			int ost=x%y;
			int dv=x/y;
			int fir=1e9,sec=1e9,zb=1e9;
			for(int j=0;j<intervals.size();j++) if(intervals[j].first<=intervals[j].second)
			{
                int l,r;tie(l,r)=intervals[j];
				auto Try=[&](int A)
				{
					int pre=A/y;
					if(A>=x)
					{
						int tmp=pre-(A-x)/y;
						if(tmp<fir) sec=fir,fir=tmp;
						else sec=min(sec,tmp);
					}
					if(A>=2*x)
					{
						zb=min(zb,pre-(A-2*x)/y);
					}
					/*ll p=1e9;
					if((A%y)>=ost && (A/y)>=dv)
					{
						p=min(p,dv);
					}
					else if((A/y)>=dv+1)
					{
						p=min(p,dv+1);
					}
					if(fir>p) sec=fir,fir=p;
					else sec=min(sec,p);
					if((A%y)>=ost*2 && (A/y)>=dv*2)
					{
						zb=min(zb,dv*2);
					}
					else if((A%y)>=ost && (A/y)>=dv*2+1)
					{
						zb=min(zb,dv*2+1);
					}
					else if((A/y)>=dv*2+2)
					{
						zb=min(zb,dv*2+2);
					}*/
				};
				Try(a[r]);
				if(r!=l) Try(a[r-1]);
			}
			ll mn=min(zb,fir+sec);
			bool ok=1;
			if(mn>=1e9) ok=0;
			if(sum-mn<x) ok=0;
			if(ok) ans=x,bot=x+1;
			else top=x-1;
 		}
 		if(ans!=-1)
		{
			sol=max(sol,(ll)y*ans);
		}
	}
	printf("%lld\n",sol);
	return 0;
}