#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
bool has[N];
int go[N],sum[N],bsq[N];
vector<int> ps[N],ds[N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1,x;i<=n;i++) scanf("%i",&x),has[x]=1;
	for(int i=2;i<N;i++) if(!go[i]) for(int j=i;j<N;j+=i) go[j]=i;
	for(int i=1;i<N;i++) for(int j=i;j<N;j+=i) has[i]|=has[j],ds[j].pb(i);
	for(int i=1;i<N;i++)
	{
		int x=i,y=i;
		while(x!=1)
		{
			if(ps[i].empty() || ps[i].back()!=go[x]) ps[i].pb(go[x]);
			else y/=go[x];
			x/=go[x];
		}
		bsq[i]=y;
	}
	ll ans=0;
	stack<int> stk;
	auto Add=[&](int i){ stk.push(i);for(int x:ds[bsq[i]]) sum[x]++;};
	auto Del=[&](){ for(int y:ds[bsq[stk.top()]]) sum[y]--;stk.pop();};
	int was=0;
	for(int i=N-1;i;i--) if(has[i])
	{
		bool ok;
		do
		{
			int cnt=0;
			for(int x:ds[bsq[i]]) if(x!=1) cnt+=((ps[x].size()&1)?1:-1)*sum[x];
			if(cnt!=stk.size())
			{
				while(__gcd(stk.top(),i)!=1) Del();
				ans=max(ans,(ll)i*stk.top());
				Del();
				ok=1;
			}
			else ok=0;
		}while(ok);
		if(stk.size()==was) Add(i);
		was++;
	}
	printf("%lld\n",ans);
	return 0;
}