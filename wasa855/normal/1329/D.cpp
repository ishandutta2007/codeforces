#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int sqr(int x){return mul(x,x);}
#define N 200005
struct Node
{
	int l,r,lid,rid,c;
};
char s[N];
set<pii> a[26],b[26];
set<int> c[26];
Node d[N];
vector<pii> ans;
int t[N],n,len,cnt;
int lowbit(int u){return u&(-u);}
void update(int u,int v)
{
	// printf("%d %d %d\n",u,n,v);
	while(u<=n) t[u]+=v,u+=lowbit(u);
}
int query(int u)
{
	int ans=0;
	while(u) ans+=t[u],u-=lowbit(u);
	return ans;
}
void solve(int l,int r)
{
	// printf("%d %d\n",l,r);
	int il=l-query(l),ir=r-query(r);
	// printf("%d %d\n",il,ir);
	len-=(ir-il+1);
	ans.pb(mp(il,ir));
	// printf("%d %d\n",r+1,ir-il+1);
	update(r+1,ir-il+1);
}
void insert(int l,int r)
{
	if(d[l].c==d[r].c) b[d[l].c].insert(mp(l,r));
	else a[d[l].c].insert(mp(l,r)),a[d[r].c].insert(mp(l,r));
}
void erase(int l,int r)
{
	/*if(a[d[l].c].find(mp(l,r))!=a[d[l].c].end())*/ a[d[l].c].erase(mp(l,r));
	/*if(a[d[r].c].find(mp(l,r))!=a[d[r].c].end())*/ a[d[r].c].erase(mp(l,r));
	/*if(b[d[l].c].find(mp(l,r))!=b[d[l].c].end())*/ b[d[l].c].erase(mp(l,r));
}
void del(int l,int r)
{
	int L=d[l].l,R=d[r].r;
	if(L) erase(L,l);
	if(R) erase(r,R);
	d[L].r=R,d[R].l=L;
	// printf("-- %d %d\n",L,R);
	if(L&&R) insert(L,R);
}
void work()
{
	for(int i=0;i<26;i++) a[i].clear(),b[i].clear(),c[i].clear();
	ans.clear();
	scanf("%s",s+1);
	n=len=strlen(s+1);
	for(int i=1;i<=n;i++) t[i]=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i+1]) continue;
		cnt++;
		d[cnt].l=cnt-1,d[cnt].r=cnt+1;
		d[cnt].lid=i,d[cnt].rid=i+1;
		d[cnt].c=s[i]-'a';
		c[s[i]-'a'].insert(cnt);
		if(cnt!=1) insert(cnt-1,cnt);
	}
	d[1].l=d[cnt].r=0;
	while(cnt)
	{
		// printf("%d\n",cnt);
		int maxn=0;
		for(int i=0;i<26;i++) if(c[i].size()>c[maxn].size()) maxn=i;
		if(a[maxn].size())
		{
			pii u=*a[maxn].begin();
			a[maxn].erase(u);
			c[d[u.fir].c].erase(u.fir);
			c[d[u.sec].c].erase(u.sec);
			if(d[u.fir].c==maxn) a[d[u.sec].c].erase(u);
			else a[d[u.fir].c].erase(u);
			del(u.fir,u.sec);
			solve(d[u.fir].rid,d[u.sec].lid);
			cnt-=2;
			continue;
		}
		if(b[maxn].size())
		{
			// cout<<"**\n";
			pii u=*b[maxn].begin();
			b[maxn].erase(u);
			c[maxn].erase(u.sec);
			del(u.sec,u.sec);
			solve(d[u.fir].rid,d[u.sec].lid);
			cnt--;
			continue;
		}
		int u=*c[maxn].begin();
		c[maxn].erase(u);
		del(u,u);
		solve(d[u].lid,d[u].rid-1);
		cnt--;
	}
	ans.pb(mp(1,len));
	printf("%d\n",(int)ans.size());
	for(pii i:ans) printf("%d %d\n",i.fir,i.sec);
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}