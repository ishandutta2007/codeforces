#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 300005
int p[N],q[N],ans[N],pos[N];
struct Node
{
	int dat,tag;
};
Node t[N*4];
#define ls (u<<1)
#define rs (u<<1|1)
void pushdown(int u)
{
	if(t[u].tag)
	{
		t[ls].tag+=t[u].tag,t[rs].tag+=t[u].tag;
		t[ls].dat+=t[u].tag,t[rs].dat+=t[u].tag;
		t[u].tag=0;
	}
}
void update(int u,int l,int r,int L,int R,int d)
{
	if(L<=l&&r<=R)
	{
		t[u].tag+=d,t[u].dat+=d;
		return ;
	}
	pushdown(u);
	int mid=(l+r)/2;
	if(mid>=L) update(ls,l,mid,L,R,d);
	if(mid<R) update(rs,mid+1,r,L,R,d);
	t[u].dat=min(t[ls].dat,t[rs].dat);
}
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) p[i]=read(),pos[p[i]]=i;
	for(int i=1;i<=n;i++) q[i]=read();
	int ans=n;
	update(1,1,n,1,pos[n],-1);
	for(int i=1;i<=n;i++)
	{
		while(t[1].dat>=0)
		{
			ans--; update(1,1,n,1,pos[ans],-1);
		}
		printf("%d ",ans);
		update(1,1,n,1,q[i],1);
	}
	return 0;
}