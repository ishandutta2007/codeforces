#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
int x[N],y[N];
vector<int> v[N];
int last[N];
int sum[N];
void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
int Get(int i){ int ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
int Get(int l, int r){ return Get(r)-Get(l-1);}
int ans[N];
vector<pair<int,int>> Qs[N];
int main()
{
	int n;
	scanf("%i",&n);
	map<pair<int,int>,int> id;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int sz;
		scanf("%i",&sz);
		for(int j=0;j<sz;j++)
		{
			scanf("%i %i",&x[j],&y[j]);
		}
		for(int j=0;j<sz;j++)
		{
			int a=x[(j+1)%sz]-x[j];
			int b=y[(j+1)%sz]-y[j];
			int g=__gcd(abs(a),abs(b));
			a/=g;
			b/=g;
			int c;
			if(!id.count({a,b})) id[{a,b}]=++cnt;
			c=id[{a,b}];
			v[i].pb(c);
		}
	}
	int q,l,r;
	scanf("%i",&q);
	for(int i=1;i<=q;i++) scanf("%i %i",&l,&r),Qs[r].pb({i,l});
	for(int i=1;i<=n;i++)
	{
		for(int j:v[i])
		{
			if(last[j]) Set(last[j],-1);
			Set(i,1);
			last[j]=i;
		}
        for(auto qu:Qs[i])
		{
			ans[qu.first]=Get(qu.second,i);
		}
	}
	for(int i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}