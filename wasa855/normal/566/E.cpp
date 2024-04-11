#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1005
bitset<N> a[N],b[N],c[N];
bool l[N];
int n,id[N];
bool vis[N],e[N][N];
signed main()
{
	cin>>n;
	bool A=1;
	for(int i=1;i<=n;i++)
	{
		int s=read();
		if(s!=n) A=0;
		while(s--) a[i][read()]=1;
	}
	if(A)
	{
		for(int i=1;i<n;i++) printf("%d %d\n",i,n);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			bitset<N> cur=a[i]&a[j];
			if(cur.count()==2)
			{
				int x=cur._Find_first(),y=cur._Find_next(x);
				e[x][y]=e[y][x]=1;
				vis[x]=vis[y]=1;
				// printf("-- %d %d\n",x,y);
			}
		}
	}
	int cnt=0;
	vector<int> qaq;
	for(int i=1;i<=n;i++) if(vis[i]) cnt++,qaq.pb(i);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int j=1;j<=n;j++) b[i][j]=1;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i])
				{
					if(a[j].count()<b[i].count()) b[i]=a[j],id[i]=j;
				}
			}
			for(int j=1;j<=n;j++) if(b[i][j]&&!vis[j]) b[i][j]=0;
		}
		else
		{
			c[i][i]=1;
			for(int j=1;j<=n;j++)
			{
				if(e[i][j]) c[i][j]=1;
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=n;j++) printf("%d ",(int)b[i][j]);
		// cout<<"\n";
	// }
	// cout<<"\n";
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=n;j++) printf("%d ",(int)c[i][j]);
		// cout<<"\n";
	// }
	if(cnt==2)
	{
		bitset<N> x,y;
		bool X=0,Y=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				bitset<N> tmp=a[id[i]];
				if(!X) x=tmp,X=1;
				if(x!=tmp) y=tmp,Y=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				bitset<N> tmp=a[id[i]];
				if(tmp!=x&&tmp!=y) return 1;
				if(tmp==x) e[i][qaq[0]]=e[qaq[0]][i]=1;
				else e[i][qaq[1]]=e[qaq[1]][i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(e[i][j]) printf("%d %d\n",i,j);
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[j]&&b[i]==c[j])
				{
					vis[i]=1;
					e[i][j]=e[j][i]=1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(e[i][j]) printf("%d %d\n",i,j);
		}
	}
	return 0;
}