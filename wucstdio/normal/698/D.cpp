#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
	Point(ll xx=0,ll yy=0){x=xx,y=yy;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	ll dot(Point p){return x*p.x+y*p.y;}
	ll det(Point p){return x*p.y-y*p.x;}
}a[1005],p[9];
bool flag[1005],used[9];
vector<int>s[8][1005];
int n,k,st[10][1005],top[10],ans;
int c[1005],t;
bool dfs(int step)
{
//	printf("dfs(%d):",step);
//	for(int i=1;i<=top[step];i++)printf("(%lld,%lld) ",a[st[step][i]].x,a[st[step][i]].y);
//	printf("\n");
	if(!top[step])return 1;
	if(top[step]>step)return 0;
	int now=st[step][top[step]--];
	for(int i=1;i<=k;i++)
	{
		if(used[i])continue;
		top[step-1]=top[step];
		for(int j=1;j<=top[step];j++)st[step-1][j]=st[step][j];
		int num=(int)s[i][now].size();
		int tt=t;
		for(int j=0;j<num;j++)
		{
			if(!flag[s[i][now][j]])
			{
				flag[s[i][now][j]]=1;
				st[step-1][++top[step-1]]=s[i][now][j];
				c[++t]=s[i][now][j];
			}
		}
		used[i]=1;
		if(dfs(step-1))return 1;
		used[i]=0;
		while(t!=tt)flag[c[t--]]=0;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&k,&n);
	for(int i=1;i<=k;i++)scanf("%lld%lld",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			printf("s[%d][%d]:\n",i,j);
			for(int k=1;k<=n;k++)
			{
				if(k==j)continue;
				if((a[j]-a[k]).det(p[i]-a[k])==0&&(a[j]-a[k]).dot(p[i]-a[k])<0)
				{
					s[i][j].push_back(k);
				}
			}
//			printf("\n");
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(flag,0,sizeof(flag));
		memset(used,0,sizeof(used));
		top[k]=0;
		st[k][++top[k]]=i;
		flag[i]=1;
//			printf("(%lld,%lld):\n",a[i].x,a[i].y);
		if(dfs(k))
		{
//			printf("ok\n");
			ans++;
		}
//		else printf("!!!(%lld,%lld)\n",a[i].x,a[i].y);
	}
	printf("%d\n",ans);
	return 0;
}