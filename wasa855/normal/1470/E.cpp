#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define lll __int128
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fll
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 500005
int n,Q,a[N],k;
struct Query{int x,p,k,pos,bad;};
lll f[N][5],g[N][4];
Query q[N];
int ans[N];
struct Node{int x,y;};
Node st[N][19];
Node merge(Node x,Node y)
{
	int A=min(INF,x.x+y.x),B=min(INF,min(x.y,x.x+y.y));
	return {A,B};
}
int getpos(int ned,int b,int k)
{
	int l=b,r=n,ans=l-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(g[mid][k]-g[b-1][k]<ned) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans+1;
}
void work()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	cin>>n>>k>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=Q;i++) q[i].p=read(),q[i].x=read(),q[i].k=k,q[i].pos=1,ans[i]=0;
	for(int i=0;i<=n;i++) f[i][0]=1;
	for(int j=1;j<=4;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[i-1][j];
			for(int k=1;k<=j&&k<i;k++) f[i][j]+=f[i-k-1][j-k];
		}
	}
	for(int j=1;j<=4;j++) for(int i=0;i<=n;i++) f[i][j]+=f[i][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=4;j++)
	{
		g[i][j-1]=0;
		for(int k=1;k<=j&&i+k<=n;k++) if(a[i+k]<a[i]) g[i][j-1]+=f[n-i-k][j-k];
	}
//	for(int i=1;i<=n;i++) for(int j=1;j<=4;j++) h[i][j-1]=f[n-i][j-1]+g[i][j-1];
//	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) printf("%lld%c",(int)g[i][j-1]," \n"[j==k]);
	for(int i=1;i<=Q;i++) if(q[i].x>f[n][k]) q[i].bad=1;
	for(int cur=k;cur>=1;cur--)
	{
		for(int i=1;i<=n;i++) st[i][0]={min((int)g[i][cur-1],INF),min((int)f[n-i][cur]+(int)g[i][cur-1],INF)};
		for(int i=1;i<=18;i++) for(int j=1;j+(1<<i)-1<=n;j++) st[j][i]=merge(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		for(int i=1;i<=Q;i++) if(q[i].k==cur)
		{
//			printf("^^ %d %d %d\n",cur,q[i].x,q[i].pos);
			for(int j=18;j>=0;j--) if(q[i].pos+(1<<j)<=n)
			{
//				printf("%d ** %d %d - %d\n",j,st[q[i].pos][j].x,st[q[i].pos][j].y,q[i].x);
				if(q[i].x>st[q[i].pos][j].x&&q[i].x<=st[q[i].pos][j].y) q[i].x-=st[q[i].pos][j].x,q[i].pos+=1<<j;
//				printf("^^ %d %d %d\n",cur,q[i].x,q[i].pos);
			}
			{
				vector<int> pos;
				for(int j=0;j<=q[i].k&&q[i].pos+j<=n;j++) pos.pb(q[i].pos+j);
				sort(pos.begin(),pos.end(),[&](int x,int y){return a[x]<a[y];});
				for(int j=0;j<(int)pos.size();j++)
				{
					int v=f[n-pos[j]][q[i].k-(pos[j]-q[i].pos)];
//					printf("^ %d %d\n",pos[j],v);
					if(q[i].x>v) q[i].x-=v;
					else
					{
						q[i].k-=pos[j]-q[i].pos;
						if(q[i].p>=q[i].pos&&q[i].p<=pos[j]) ans[i]=a[pos[j]-(q[i].p-q[i].pos)];
//						if(pos[j]!=q[i].pos) opt.eb(i,pos[j]);
						q[i].pos=pos[j]+1;
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=Q;i++) if(!ans[i]) ans[i]=a[q[i].p];
	for(int i=1;i<=Q;i++)
	{
		if(!q[i].bad) printf("%lld\n",ans[i]);
		else puts("-1");
	}
}
signed main()
{
	// cerr<<(sizeof(f)+sizeof(g)+sizeof(st))/1024.0/1024.0<<endl;
	int T=read(); while(T--) work();
	
	return 0;
}