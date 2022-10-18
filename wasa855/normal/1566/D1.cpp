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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 305
int a[N][N],id[N*N],val[N*N],n,m;
struct Node{int x,y;}b[N*N],c[N*N];
bool cmp(Node x,Node y) {return x.x<y.x||(x.x==y.x&&x.y>y.y);}
void work()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=0;
	for(int i=1;i<=n*m;i++) val[i]=read(),id[i]=i;
	sort(id+1,id+n*m+1,[&](int x,int y) {return val[x]<val[y]||(val[x]==val[y]&&x<y);});
	int tx=1,ty=1;
	for(int i=1;i<=n*m;i++)
	{
		int j=i,cnt=0;
		while(j<=n*m&&val[id[i]]==val[id[j]])
		{
			c[++cnt]=(Node){tx,ty};
			ty++; if(ty>m) ty=1,tx++;
			j++;
		}
		// printf("^ %d %d\n",i,j);
		sort(c+1,c+cnt+1,cmp);
		cnt=0;
		for(int k=i;k<j;k++) b[id[k]]=c[++cnt];
		i=j-1;
	}
	// for(int i=1;i<=n*m;i++) printf("%d %d\n",b[i].x,b[i].y);
	ll ans=0;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=b[i].y;j++) ans+=a[b[i].x][j];
		a[b[i].x][b[i].y]=1;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}