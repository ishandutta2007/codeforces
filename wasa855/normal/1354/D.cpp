#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1000005
int siz[N*4];
#define ls (u<<1)
#define rs (u<<1|1)
void insert(int u,int l,int r,int p)
{
	if(l==r) {siz[u]++; return ;}
	int mid=(l+r)/2;
	if(p<=mid) insert(ls,l,mid,p);
	else insert(rs,mid+1,r,p);
	siz[u]=siz[ls]+siz[rs];
}
void erase(int u,int l,int r,int p)
{
	if(l==r) {siz[u]--; return ;}
	int mid=(l+r)/2;
	if(siz[ls]>=p) erase(ls,l,mid,p);
	else erase(rs,mid+1,r,p-siz[ls]);
	siz[u]=siz[ls]+siz[rs];
}
int get(int u,int l,int r)
{
	if(l==r) return l;
	int  mid=(l+r)/2;
	if(siz[ls]) return get(ls,l,mid);
	else if(siz[rs]) return get(rs,mid+1,r);
	return 0;
}
signed main()
{
	int n,Q;
	cin>>n>>Q;
	for(int i=1;i<=n;i++) insert(1,1,n,read());
	for(int i=1;i<=Q;i++)
	{
		int x=read();
		if(x>0) insert(1,1,n,x);
		else erase(1,1,n,-x);
	}
	cout<<get(1,1,n)<<endl;
	return 0;
}