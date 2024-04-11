#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=1e5+5;
int s[max_n],id[max_n];
long long val[max_n],ans=1e18;
inline bool cmp(int x,int y)
{
	return val[x]<val[y];
}
const int T=1;
const int D=10;
inline long long calc(int x,int y)
{
	return 1ll*(x-y)*(x-y)+1ll*(s[x]-s[y])*(s[x]-s[y]);
}
inline void solve(int dx,int dy)
{
	for(int i=1;i<=n;++i)
		val[i]=1ll*(i+dx)*(s[i]+dy);
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		int x=id[i];
		for(int j=i+1;j<=i+D&&j<=n;++j)
			ans=min(ans,calc(x,id[j]));
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		s[i]=s[i-1]+a;
		id[i]=i;
	}
// 	solve(0,0);
	srand(chrono::steady_clock::now().time_since_epoch().count()); 
	for(int t=1;t<=T;++t)
		solve(rand()&1?-rand():rand(),rand()&1?-rand():rand());
	printf("%lld\n",ans);
	return 0;
}