#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
map<pair<int,int>,int>mp;
int t,n;
char s[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		mp.clear();
		mp[make_pair(0,0)]=1;
		int ans=n+1,l,r;
		int x=0,y=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='L')x--;
			if(s[i]=='R')x++;
			if(s[i]=='U')y--;
			if(s[i]=='D')y++;
			int v=mp[make_pair(x,y)];
			if(v)
			{
				if(ans>i-v+1)
				{
					ans=i-v+1;
					l=v,r=i;
				}
			}
			mp[make_pair(x,y)]=i+1;
		}
		if(ans==n+1)printf("-1\n");
		else printf("%d %d\n",l,r);
	}
	return 0;
}