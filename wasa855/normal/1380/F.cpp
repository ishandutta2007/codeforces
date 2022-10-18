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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 500005
struct Mat
{
	int a[2][2];
	Mat(){memset(a,0,sizeof(a));}
	void print()
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++) printf("%d ",a[i][j]);
			cout<<"\n";
		}
	}
	Mat operator * (const Mat x) const
	{
		Mat ans;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) ans.a[i][j]=add(ans.a[i][j],mul(a[i][k],x.a[k][j]));
		return ans;
	}
};
Mat t[N*4];
int a[N];
#define ls (u<<1)
#define rs (u<<1|1)
int calc(int x)
{
	if(x>=19) return 0;
	if(x>=10) return 19-x;
	return x+1;
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		t[u].a[0][0]=calc(a[l]);
		if(a[l-1]!=0) t[u].a[1][0]=calc(a[l-1]*10+a[l]);
		t[u].a[0][1]=1;
		return ;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[u]=t[ls]*t[rs];
}
void update(int u,int l,int r,int pl)
{
	if(l==r)
	{
		t[u].a[0][0]=calc(a[l]);
		if(a[l-1]!=0) t[u].a[1][0]=calc(a[l-1]*10+a[l]);
		else t[u].a[1][0]=0;
		t[u].a[0][1]=1;
		return ;
	}
	int mid=(l+r)/2;
	if(pl<=mid) update(ls,l,mid,pl);
	else update(rs,mid+1,r,pl);
	t[u]=t[ls]*t[rs];
}
int query()
{
	return t[1].a[0][0];
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int p=read(),u=read();
		a[p]=u;
		update(1,1,n,p);
		if(p!=n) update(1,1,n,p+1);
		printf("%d\n",query());
	}
	return 0;
}