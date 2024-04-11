#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
typedef pair<int,int> pii;
#define INF 1e18
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
struct Edge
{
	int v,nxt;
};
Edge edge[N*2];
int fir[N],ss;
void add(int u,int v)
{
	ss++;
	edge[ss].v=v;
	edge[ss].nxt=fir[u];
	fir[u]=ss;
	ss++;
	edge[ss].v=u;
	edge[ss].nxt=fir[v];
	fir[v]=ss;
}
int dgr[N];
int a[N][5];
int f[N][5][5];
int b[N];
int fr[N];
int ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int j=1;j<=3;j++)
	{
		for(int i=1;i<=n;i++) a[i][j]=read();
	}
//	cout<<"passed\n";
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		dgr[u]++,dgr[v]++;
	}
	int rt=0,las=0,ed=0;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]>2)
		{
			cout<<"-1\n";
			return 0;
		}
		if(dgr[i]==1&&!rt) rt=i;
		else if(dgr[i]==1) ed=i;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) for(int k=1;k<=3;k++) f[i][j][k]=INF;
	for(int i=1;i<=n;i++)
	{
		b[i]=rt;
		for(int j=fir[rt];j!=0;j=edge[j].nxt)
		{
			int v=edge[j].v;
			if(v!=las)
			{
				las=rt,rt=v;
				break;
			}
		}
	}
	int minn=INF;
	int c[5];
	for(c[1]=1;c[1]<=3;c[1]++)
	{
		for(c[2]=1;c[2]<=3;c[2]++)
		{
			if(c[1]==c[2]) continue;
			for(c[3]=1;c[3]<=3;c[3]++)
			{
				if(c[1]==c[3]||c[2]==c[3]) continue;
				int res=0;
				for(int i=1;i<=n;i++)
				{
					res+=a[b[i]][c[i%3+1]];
				}
				if(res<minn)
				{
					minn=res;
					for(int i=1;i<=n;i++)
					{
						ans[b[i]]=c[i%3+1];
					}
				}
			}
		}
	}
	cout<<minn<<endl;
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}