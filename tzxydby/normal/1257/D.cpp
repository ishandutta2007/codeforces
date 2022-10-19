#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N],dp[N],n,m,t;
pair<int,int>p[N];
multiset<int>s;
map<int,int>f;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&p[i].first,&p[i].second);
		s.clear();
		f.clear();
		sort(b+1,b+n+1);
		reverse(b+1,b+n+1);
		sort(p+1,p+m+1);
		reverse(p+1,p+m+1);
		if(b[1]>p[1].first)
		{
			puts("-1");
			continue;	
		} 
		int ms=0;
		for(int i=1,j=1;i<=n;i++)
		{
			while(j<=m&&p[j].first>=b[i])
			{
				ms=max(ms,p[j].second);
				j++;
			}
			f[b[i]]=ms;
		}
		s.insert(-a[1]);
		for(int i=1,j=1;i<=n;i++)
		{
			while(j<=n&&(s.size()==0||f[-*(s.begin())]>=j-i+1))
			{
				j++;
				s.insert(-a[j]);
			}
			dp[i]=j-1;
			s.erase(s.find(-a[i]));
		}
		int ans=0,i=1;
		while(1)
		{
			i=dp[i]+1;
			ans++;
			if(i>n)
				break; 
		}
		printf("%d\n",ans);
	}
	return 0;
}