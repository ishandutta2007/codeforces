#include<bits/stdc++.h>
using namespace std;
const int max_n=3e3+5;
int l[max_n],r[max_n];
const int max_R=6e3+5;
int Hash[max_R];
vector<int> seg[max_R];
int dp[max_R][max_R];
bool vis[max_R][max_R];
int calc(int x,int y)
{
	if(x>y)
		return 0;
	if(vis[x][y])
		return dp[x][y];
	dp[x][y]=calc(x+1,y);
	for(vector<int>::iterator it=seg[x].begin();it!=seg[x].end();++it)
	{
		int now=*it;
		if(now<y)
			dp[x][y]=max(dp[x][y],calc(x,now)+calc(now+1,y));
		else if(now==y)
			++dp[x][y];
		else
			break;
	}
	vis[x][y]=true;
	return dp[x][y];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int R=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",l+i,r+i);
			Hash[++R]=l[i];
			Hash[++R]=r[i];
		}
		sort(Hash+1,Hash+R+1);
		R=unique(Hash+1,Hash+R+1)-Hash-1;
		for(int i=1;i<=R;++i)
			seg[i].clear();
		for(int i=1;i<=n;++i)
		{
			l[i]=lower_bound(Hash+1,Hash+R+1,l[i])-Hash;
			r[i]=lower_bound(Hash+1,Hash+R+1,r[i])-Hash;
			seg[l[i]].push_back(r[i]);
		}
		for(int i=1;i<=R;++i)
			sort(seg[i].begin(),seg[i].end());
		for(int i=1;i<=R;++i)
			for(int j=i;j<=R;++j)
				vis[i][j]=false;
		printf("%d\n",calc(1,R));
	}
	return 0;
}