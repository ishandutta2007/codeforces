#include<bits/stdc++.h>
using namespace std;
map<long long,int> cnt;
bool ans;
inline void solve(long long w)
{
	if(!ans)
		return;
	if(cnt[w]>0)
	{
		--cnt[w];
		return;
	}
	if(w==1)
	{
		ans=false;
		return;
	}
	solve(w>>1);
	if(!ans)
		return;
	solve((w+1)>>1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt.clear();
		int n;
		scanf("%d",&n);
		long long sum=0;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			sum+=a;
			++cnt[a];
		}
		ans=true;
		solve(sum);
		puts(ans?"YES":"NO");
	}
	return 0;
}