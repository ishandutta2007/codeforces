#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 1000005
#define ls (u<<1)
#define rs (u<<1|1)
char ch[N];
char s[N];
int n;
int maxn[N*4],minn[N*4],tag[N*4];
void pushdown(int u)
{
	maxn[ls]+=tag[u];
	minn[ls]+=tag[u];
	tag[ls]+=tag[u];
	maxn[rs]+=tag[u];
	minn[rs]+=tag[u];
	tag[rs]+=tag[u];
	tag[u]=0;
}
void update(int u,int l,int r,int L,int R,int d)
{
	if(L<=l&&r<=R)
	{
		maxn[u]+=d,minn[u]+=d;
		tag[u]+=d;
		return ;
	}
	pushdown(u);
	int mid=(l+r)/2;
	if(mid>=L) update(ls,l,mid,L,R,d);
	if(mid<R) update(rs,mid+1,r,L,R,d);
	maxn[u]=max(maxn[ls],maxn[rs]);
	minn[u]=min(minn[ls],minn[rs]);
}
pii query(int u,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return mp(minn[u],maxn[u]);
	pushdown(u);
	int mid=(l+r)/2;
	pii ans=mp(N,-N);
	if(mid>=L)
	{
		pii res=query(ls,l,mid,L,R);
		if(res.fir<ans.fir) ans.fir=res.fir;
		if(res.sec>ans.sec) ans.sec=res.sec;
	}
	if(mid<R)
	{
		pii res=query(rs,mid+1,r,L,R);
		if(res.fir<ans.fir) ans.fir=res.fir;
		if(res.sec>ans.sec) ans.sec=res.sec;
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	scanf("%s",s+1);
	int pl=1;
	int tsum=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		{
			if(pl!=1) pl--;
		}
		else if(s[i]=='R') pl++;
		else
		{
			if(ch[pl]=='(') update(1,1,n,pl,n,-1),tsum--;
			if(ch[pl]==')') update(1,1,n,pl,n,1),tsum++;
			ch[pl]=s[i];
			if(ch[pl]=='(') update(1,1,n,pl,n,1),tsum++;
			if(ch[pl]==')') update(1,1,n,pl,n,-1),tsum--;
		}
		pii tmp=query(1,1,n,1,n);
		if(tmp.fir<0||tsum!=0) printf("-1 ");
		else printf("%d ",tmp.sec);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}