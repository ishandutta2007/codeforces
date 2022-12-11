#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
typedef pair<int,int> P;
const int S=1<<15|5;
int n,m,k,t,sx,sy;
int x[15],y[15],v[15];
bool mark[25][25];
char s[25];
int num[25][25];
int Log[S],sum[S];
void init()
{
	for(int i=0;i<k;i++) Log[1<<i]=i;
	for(int s=1;s<=t;s++)
		sum[s]=sum[s-(s&(-s))]+v[Log[s&(-s)]+1];
	for(int a=1;a<=n;a++)
		for(int b=1;b<=m;b++)
			for(int i=1;i<=k;i++)
				if(x[i]==a&&y[i]<=b) num[a][b]|=1<<i-1;
}
bool inq[25][25][S];
int f[25][25][S];
int work(int x,int y,int a,int s)
{
	return x==a?s:s^num[max(x,a)][y];
}
struct node
{
	int x,y,s;
	node(int x1,int y1,int s1) {x=x1,y=y1,s=s1;}
};
int dx[5]={0,-1,1,0},dy[5]={-1,0,0,1}; 
int solve(int x,int y)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int s=0;s<=t;s++)
				inq[i][j][s]=false,f[i][j][s]=1e9;
	f[x][y][0]=0;
	queue<node> q;
	q.push(node(x,y,0));
	inq[x][y][0]=true;
	while(q.size())
	{
		int x=q.front().x,y=q.front().y,s=q.front().s;
		q.pop();
		inq[x][y][s]=false;
		for(int i=0;i<4;i++)
		{
			int a=x+dx[i],b=y+dy[i];
			if((a>0&&a<=n&&b>0&&b<=m)&&!mark[a][b])
			{
				int ss=work(x,y,a,s);
				if(f[a][b][ss]>f[x][y][s]+1)
				{
					f[a][b][ss]=f[x][y][s]+1;
					q.push(node(a,b,ss));
					inq[a][b][ss]=true;
				}
			}
		}
	}
	int ans=0;
	for(int s=0;s<=t;s++) ans=max(ans,sum[s]-f[x][y][s]);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	vector<P> bomb;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='B')
			{
				bomb.push_back(P(i,j));
				mark[i][j]=true;
			}
			else if(s[j]=='S') sx=i,sy=j;
			else if(s[j]>='1'&&s[j]<='8')
			{
				k++;
				x[s[j]-'0']=i,y[s[j]-'0']=j;
				mark[i][j]=true;
			}
			else if(s[j]=='#') mark[i][j]=true;
		}
	}
	for(int i=1;i<=k;i++) scanf("%d",v+i);
	for(int i=0;i<bomb.size();i++)
		x[++k]=bomb[i].first,y[k]=bomb[i].second,v[k]=-1e5;
	t=(1<<k)-1;
	init();
	printf("%d",solve(sx,sy));
	return 0;
}