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
#define N 400005
int a[N],ban[N],n,m;
struct Node
{
	int l,r;
};
Node b[N];
bool cmp(Node x,Node y) {return x.l<y.l||(x.l==y.l&&x.r>y.r);}
int f[N],g[N],t[N];
void work()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	a[++n]=-1e12,a[++n]=1e12;
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		int pos=lower_bound(a+1,a+n+1,l)-a;
		if(pos<=n&&a[pos]<=r) i--,m--;
		else b[i]=(Node){l,r};
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++) ban[i]=0;
	// for(int i=1;i<=m;i++) printf("%lld %lld\n",b[i].l,b[i].r);
	int sufmin=INF;
	for(int i=m;i>=1;i--)
	{
		if(b[i].r>=sufmin) ban[i]=1;
		sufmin=min(sufmin,b[i].r);
	}
	int tm=0;
	for(int i=1;i<=m;i++)
	{
		if(!ban[i]) tm++,swap(b[i],b[tm]);
	}
	m=tm;
	if(!m) {printf("0\n"); return ;}
	for(int i=1;i<=n;i++) b[++m]=(Node){a[i],a[i]};
	sort(b+1,b+m+1,cmp);
	// for(int i=1;i<=m;i++) printf("%lld %lld\n",b[i].l,b[i].r);
	for(int i=1;i<=m;i++) f[i]=g[i]=t[i]=INF;
	f[1]=g[1]=t[1]=0;
	int las=1,cur=1;
	for(int i=1;i<=n;i++)
	{
		int pos=cur,tmp=cur;
		while(cur<=m&&b[cur].r<=a[i])
		{
			// while(pos<tmp&&b[cur-1].l-a[i-1]>a[i-1]-b[pos].r) pos++;
			while(pos>las&&b[cur-1].l-a[i-1]>a[i-1]-b[pos-1].r) pos--;
			// printf("^ %lld %lld ** %lld %lld +++ %lld %lld\n",cur,pos,tmp,las,g[pos]+2*max(b[cur-1].l-a[i-1],0LL),f[pos-1]+max(b[cur-1].l-a[i-1],0LL));
			if(pos<tmp) t[cur]=min(t[cur],g[pos]+max(b[cur-1].l-a[i-1],0LL));
			if(pos>las) t[cur]=min(t[cur],f[pos-1]+2*max(b[cur-1].l-a[i-1],0LL));
			cur++;
		}
		{
			
		}
		cur--;
		for(int j=tmp;j<=cur;j++) f[j]=t[j]+a[i]-b[j].r,g[j]=t[j]+(a[i]-b[j].r)*2;
		for(int j=tmp+1;j<=cur;j++) f[j]=min(f[j],f[j-1]);
		for(int j=cur-1;j>=tmp;j--) g[j]=min(g[j],g[j+1]);
		las=tmp;
		cur++;
	}
	// for(int i=1;i<=m;i++) printf("%lld%c",t[i]," \n"[i==m]);
	// for(int i=1;i<=m;i++) printf("%lld%c",f[i]," \n"[i==m]);
	// for(int i=1;i<=m;i++) printf("%lld%c",g[i]," \n"[i==m]);
	printf("%lld\n",f[m]);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}