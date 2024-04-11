#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

//vector<P> a,b;

P a[100100],b[100100];
#if 0
vector<int> graph[200200];

int match[200200];
bool used[200200];

int V;

bool dfs(int v)
{
	used[v]=true;
	for(int i=0;i<graph[v].size();i++)
	{
		int u=graph[v][i],w=match[u];
		{
			if(w<0||!used[w]&&dfs(w))
			{
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
	}
	return false;
}

int bip_match()
{
	int res=0;
	memset(match,-1,sizeof(match));
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			memset(used,0,sizeof(used));
			if(dfs(v))
			{
				res++;
			}
		}
	}
	return res;
}
#endif
int main()
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<n;i++)
	{
		int ina;
		scanf("%d",&ina);
		a[i]=P(ina,i+1);
	//	a.push_back(P(ina,i+1));
	}
	for(int i=0;i<m;i++)
	{
		int inb;
		scanf("%d",&inb);
		b[i]=P(inb,i+1);
	//	b.push_back(P(inb,i+1));
	}
//#if 0
//	sort(a.begin(),a.end());
//	sort(b.begin(),b.end());
	sort(a,a+n);
	sort(b,b+m);
#if 0
	for(int i=0;i<n;i++)
	{
		int s=lower_bound(b,b+m,P(a[i].first-x,0))-b;
		int t=upper_bound(b,b+m,P(a[i].first+y,100100))-b;

	//	int s=lower_bound(b.begin(),b.end(),a[i]-x)-b.begin();
	//	int t=upper_bound(b.begin(),b.end(),a[i]+y)-b.begin();
		for(int j=s;j<t;j++)
		{
			graph[i].push_back(j+n);
			graph[j+n].push_back(i);
		}

	}
	V=n+m;
//#endif
	int ans=bip_match();
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
	{
		if(match[i]>0)
		{
			printf("%d %d\n",a[i].second,b[match[i]-n].second);
		}
	}
#endif
	int i=0,j=0;
	int cnt=0;
	vector<P> match;
	while(i<n&&j<m)
	{
		if(a[i].first-x<=b[j].first&&a[i].first+y>=b[j].first)
		{
			cnt++;
			match.push_back(P(i,j));
			i++;
			j++;
			continue;
		}
		else if(a[i].first-x>b[j].first)
		{
			j++;
			continue;
		}
		else if(a[i].first+y<b[j].first)
		{
			i++;
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		printf("%d %d\n",a[match[i].first].second,b[match[i].second].second);
	}
	return 0;
}