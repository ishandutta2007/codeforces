#include <bits/stdc++.h>
#define Maxn 10000007
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return (long long)x*f;
}
int n,m,cnt,r;
long long a,b;
int pre[Maxn],other[Maxn],last[Maxn];
int tot[200007],f[200007],next[200007],path[200007];
bool vis[200007];
set<int> st[200007];
set<int>::iterator it;
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
int tryit(int x)
{
	if (vis[x]) return f[x];
	vis[x]=true;
	f[x]=0;
	for (int q=last[x];q;q=pre[q])
	{
		int v=other[q];
		int now=tryit(v);
		if (now>f[x]) 
		{
			f[x]=now;
			next[x]=v;
		}
	}
	f[x]=f[x]+tot[x];
	return f[x];
}
int exgcd(int a,int b,long long &x,long long &y)
{
	if (b==0) {x=1,y=0;return a;}
	int t=exgcd(b,a%b,y,x);
	y=y-1LL*(a/b)*x;
	return t;
}
int deal(int x,int y)
{
	int x1=x,y1=y,m1,g=gcd(y,m);
	x=x/g,y=y/g,m1=m/g;
	int r=exgcd(y,m1,a,b);
	a=a*x;
	while (a<0) a=a+m1;
	a=a%m1;
if ((a*y1)%m!=x1%m) cout << x1<<' ' << y1 << ' '<<a<<' '<<x<<' '<<y<<' '<<m1<<endl;
	return a;
}
int main()
{
	n=read(),m=read();
	memset(tot,0,sizeof(tot));
	memset(next,0,sizeof(next));
	for (int i=1;i<m;i++) 
	{
		++tot[gcd(i,m)];
		st[gcd(i,m)].insert(i);
	}
	++tot[m],st[m].insert(0);
	for (int i=1;i<=n;i++)
	{
		int x=read();
		--tot[gcd(x,m)];
		st[gcd(x,m)].erase(x);
	}
	cnt=0;
	for (int i=1;i<=m;i++)
		for (int j=2;j<=m/i;j++)
		{
			int k=i*j;
			insert(i,k);
		}
	memset(f,0,sizeof(f));
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=m;i++)
		if (!vis[i]) f[i]=tryit(i);
	int ans=0;
	for (int i=1;i<=m;i++)
		if (f[i]>f[ans]) ans=i;
	cout << f[ans] << endl;
	int last=1;
	r=0;
	while (next[ans]>0)
	{
//cout << ans << "~~~"<< tot[ans]<<endl;
		for (it=st[ans].begin();it!=st[ans].end();it++)
		{
			cout << deal(*it,last) << ' ';
			//path[++r]=deal(*it,last);
//if ((1LL*path[r]*last)%m!=(*it)%m) cout << r << "~~~"<<path[r]<<' '<<last<<endl;
			last=*it;
		}
		ans=next[ans];
	}
    for (it=st[ans].begin();it!=st[ans].end();it++)
		{
			cout << deal(*it,last) << ' ';
			//path[++r]=deal(*it,last);
//if ((1LL*path[r]*last)%m!=(*it)%m) cout << r << "~~~"<<path[r]<<' '<<last<<endl;
			last=*it;
		}
	return 0;
}