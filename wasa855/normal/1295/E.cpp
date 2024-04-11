#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
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
#define N 200005
#define ls (u<<1)
#define rs (u<<1|1)
struct Node
{
	int dat,tag;
};
Node t[N*4];
int a[N],w[N],r[N];
void pd(int u)
{
	if(t[u].tag)
	{
		t[ls].dat+=t[u].tag,t[ls].tag+=t[u].tag;
		t[rs].dat+=t[u].tag,t[rs].tag+=t[u].tag;
		t[u].tag=0;
	}
}
void update(int u,int l,int r,int L,int R,int d)
{
	if(L<=l&&r<=R)
	{
		t[u].dat+=d,t[u].tag+=d;
		return ;
	}
	pd(u);
	int mid=(l+r)/2;
	if(mid>=L) update(ls,l,mid,L,R,d);
	if(mid<R) update(rs,mid+1,r,L,R,d);
	t[u].dat=min(t[ls].dat,t[rs].dat);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) r[a[i]]=i;
	for(int i=1;i<=n;i++) w[i]=read();
	int sum=0;
	for(int i=1;i<n;i++)
	{
		sum+=w[i];
		update(1,1,n-1,i,i,sum);
	}
	int ans=t[1].dat;
	for(int i=1;i<=n;i++)
	{
//		printf("%d %d\n",r[i]-1,w[r[i]]);
		if(r[i]!=1) update(1,1,n-1,1,r[i]-1,w[r[i]]);
//		cout<<"Passed\n";
		if(r[i]!=n) update(1,1,n-1,r[i],n-1,-w[r[i]]);
		if(t[1].dat<ans) ans=t[1].dat;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}