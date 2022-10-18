#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 3505
#define ls (u<<1)
#define rs (u<<1|1)
int a[N];
int t[N*4];
void build(int u,int l,int r)
{
	if(l==r)
	{
		t[u]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(ls,l,mid),build(rs,mid+1,r);
	t[u]=min(t[ls],t[rs]);
}
int query(int u,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return t[u];
	int mid=(l+r)/2;
	int ans=INF;
	if(mid>=L) ans=min(ans,query(ls,l,mid,L,R));
	if(mid<R) ans=min(ans,query(rs,mid+1,r,L,R));
	return ans;
}
void work()
{
	int n,m,k;
	cin>>n>>m>>k;
	int c=max(m-k-1,0);
	k=min(m-1,k);
	for(int i=1;i<=n;i++) a[i]=read();
	int maxn=0;
	for(int i=0;i<=k;i++)
	{
		int minn=INF;
		for(int j=0;j<=c;j++)
		{
			int l=i+j+1,r=n-k+i-c+j;
			int res=max(a[l],a[r]);
//			printf("%d %d %d\n",i,j,res);
			if(res<minn) minn=res;
		}
//		printf("%d %d\n",i,minn);
		if(minn>maxn) maxn=minn;
	}
	cout<<maxn<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}