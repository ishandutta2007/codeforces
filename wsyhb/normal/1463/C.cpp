#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
long long t[max_n],x[max_n];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%lld%lld",t+i,x+i);
		t[n+1]=1e18;
		long long l=0,r=0,from=0,to=0;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(t[i]>=r)
			{
				from=to,to=x[i];
				l=t[i],r=t[i]+abs(from-to);
				if(r<=t[i+1])
					++ans;
			}
			else
			{
				long long l_now=from+(to-from)/(r-l)*(t[i]-l);
				long long r_now=from+(to-from)/(r-l)*min(t[i+1]-l,r-l);
				if(l_now>r_now)
					swap(l_now,r_now);
				if(l_now<=x[i]&&x[i]<=r_now)
					++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}