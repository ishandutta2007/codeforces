#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
int mod;
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 50005
int n,k;
int s[N];
struct Mar
{
	int a[2][2];
	Mar() {memset(a,0,sizeof(a));}
};
Mar operator * (Mar x,Mar y)
{
	Mar ans;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans.a[i][j]=add(ans.a[i][j],mul(x.a[i][k],y.a[k][j]));
			}
		}
	}
	return ans;
}
Mar a[N],b[N],ans;
Mar qpow(Mar x,int y,Mar ans)
{
	while(y)
	{
		if(y&1) ans=ans*x;
		x=x*x;
		y>>=1;
	}
	return ans;
}
struct NODE
{
	int x,y,k;
};
NODE q[N*2];
bool cmp(NODE x,NODE y)
{
	return x.x<y.x;
}
Mar t[N*4];
#define ls (u<<1)
#define rs (u<<1|1)
void build(int u,int l,int r)
{
	if(l==r) {t[u]=a[l]; return ;}
	int mid=(l+r)/2;
	build(ls,l,mid),build(rs,mid+1,r);
	t[u]=t[ls]*t[rs];
}
void update(int u,int l,int r,int p,Mar x)
{
	if(l==r) {t[u]=x; return ;}
	int mid=(l+r)/2;
	if(p<=mid) update(ls,l,mid,p,x);
	else update(rs,mid+1,r,p,x);
	t[u]=t[ls]*t[rs];
}
void print(Mar x)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++) printf("%lld ",x.a[i][j]);
		cout<<"\n";
	}
	cout<<"\n";
}
signed main()
{
	cin>>k>>mod>>n;
	for(int i=0;i<n;i++) s[i]=read()%mod;
	for(int i=1;i<=n;i++)
	{
		a[i].a[0][1]=s[i-1],a[i].a[1][1]=s[i%n],a[i].a[1][0]=1;
		b[i]=a[i];;
	}
	int m=read();
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		q[i].x=read(),q[i+m].x=q[i].x+1;
		q[i].k=1;
		q[i].y=q[i+m].y=read()%mod;
	}
	m*=2;
	sort(q+1,q+m+1,cmp);
	while(q[m].x>k) m--;
	ans.a[0][1]=1;
	int las=0;
	for(int i=1,j=1;i<=m;j++,i=j)
	{
		int id=(q[i].x-1)/n;
		while(j<m&&(q[j+1].x-1)/n==id) j++;
		ans=qpow(t[1],id-las,ans); las=id;
		for(int k=i;k<=j;k++)
		{
			int _id=(q[k].x-1)%n+1;
			b[_id].a[q[k].k][1]=q[k].y;
			update(1,1,n,_id,b[_id]);
		}
		if(id==k/n) break;
		ans=ans*t[1]; las++;
		for(int k=i;k<=j;k++)
		{
			int _id=(q[k].x-1)%n+1;
			b[_id]=a[_id];
			update(1,1,n,_id,b[_id]);
		}
	}
	int id=k/n;
	ans=qpow(t[1],id-las,ans);
	// print(ans);
	// for(int i=1;i<=k%n;i++) print(b[i]);
	for(int i=1;i<=k%n;i++) ans=ans*b[i];
	// print(ans);
	cout<<ans.a[0][0]<<endl;
	return 0;
}