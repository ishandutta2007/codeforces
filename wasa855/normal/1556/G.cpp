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
// #define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline ll read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	ll ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 50005*55
#define M 100005
int ls[N*4],rs[N*4],hav[N*4];
int fa[N*4],ok[N*4],cnt=1,rt=1;
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
int n,Q,op[M],ans[M];
ll l[M],r[M],t[M*2];
char _s[M];
ll ful;
void merge(int u,int v) {fa[find(u)]=find(v);}
void ins(int &u,ll l,ll r,ll L,ll R)
{
	if(L>R) return ;
	if(!u) u=++cnt,fa[u]=u;
	// printf("# %d %lld %lld\n",u,l,r);
	if(L<=l&&r<=R) return ;
	ll mid=(l+r)/2;
	if(mid>=L) ins(ls[u],l,(l+r)/2,L,R);
	if(mid<R) ins(rs[u],(l+r)/2+1,r,L,R);
}
int query(int u,ll l,ll r,ll L,ll R)
{
	if(L>R) return -1;
	if(!u) return -1;
	if(L<=l&&r<=R&&!ok[u]) return -1;
	if(!ok[u]) return -1;
	if(!ls[u]&&!rs[u]) return u;
	ll mid=(l+r)/2;
	if(mid>=L)
	{
		int res=query(ls[u],l,mid,L,R);
		if(res!=-1) return res;
	}
	if(mid<R)
	{
		int res=query(rs[u],mid+1,r,L,R);
		if(res!=-1) return res;
	}
	return -1;
}
void update(int u,ll l,ll r,ll L,ll R,int to)
{
	// printf("++ %d %lld %lld %lld %lld * %d\n",u,l,r,L,R,to);
	if(!u) return ;
	if(!ok[u]) return ;
	if(!ls[u]&&!rs[u])
	{
		hav[u]=u,merge(u,to);
		return ;
	}
	if(hav[u]) {merge(hav[u],to); return ;}
	ll mid=(l+r)/2;
	if(mid>=L) update(ls[u],l,mid,L,R,to);
	if(mid<R) update(rs[u],mid+1,r,L,R,to);
	if(find(hav[ls[u]])==find(hav[rs[u]])) hav[u]=find(hav[ls[u]]);
}
struct Node{ll l1,r1,l2,r2;};
Node get(ll l,ll r,ll L,ll R)
{
	if(L==R) return (Node){L,R,L,R};
	while(1)
	{
		ll mid=(l+r)/2;
		int A=mid>=L,B=mid<R;
		if(A&&B) return (Node){L,mid,mid+1,R};
		if(mid>=L) r=mid;
		else l=mid+1;
	}
}
void fix(int u,ll l,ll r,ll L,ll R)
{
	if(L>R) return ;
	// if(l==0&&r==ful) printf("%lld %lld\n",L,R);
	if(L<=l&&r<=R) {ok[u]=1; return ;}
	ll mid=(l+r)/2;
	if(mid>=L) fix(ls[u],l,(l+r)/2,L,R);
	if(mid<R) fix(rs[u],(l+r)/2+1,r,L,R);
	if(mid>=L)
	{
		// printf("****** %d %lld %lld\n",u,l,r);
		ll vl=max(L,l),vr=min(mid,R);
		Node qwq=get(l,mid,vl,vr);
		vl=qwq.l1,vr=qwq.r1;
		update(rs[u],mid+1,r,vl-l+mid+1,vr-l+mid+1,query(ls[u],l,mid,vl,vr));
		// printf("^^ %lld %lld - %lld %lld ** %d\n",vl,vr,vl-l+mid+1,vr-l+mid+1,res);
		vl=qwq.l2,vr=qwq.r2;
		update(rs[u],mid+1,r,vl-l+mid+1,vr-l+mid+1,query(ls[u],l,mid,vl,vr));
		// printf("^^ %lld %lld - %lld %lld ** %d\n",vl,vr,vl-l+mid+1,vr-l+mid+1,res);
	}
	if(mid<R)
	{
		// printf("$$$$$$$ %d %lld %lld\n",u,l,r);
		ll vl=max(L,mid+1),vr=min(R,r);
		Node qwq=get(mid+1,r,vl,vr);
		vl=qwq.l1,vr=qwq.r1;
		update(ls[u],l,mid,vl-mid-1+l,vr-mid-1+l,query(rs[u],mid+1,r,vl,vr));
		// printf("&& %lld %lld - %lld %lld ** %d\n",vl,vr,vl-mid-1+l,vr-mid-1+l,res);
		vl=qwq.l2,vr=qwq.r2;
		update(ls[u],l,mid,vl-mid-1+l,vr-mid-1+l,query(rs[u],mid+1,r,vl,vr));
		// printf("&& %lld %lld - %lld %lld ** %d\n",vl,vr,vl-mid-1+l,vr-mid-1+l,res);
	}
	ok[u]=ok[ls[u]]|ok[rs[u]];
}
int getfa(int u,ll l,ll r,ll pos)
{
	// printf("@ %d %lld %lld - %lld\n",u,l,r,pos);
	if(!ls[u]&&!rs[u])
	{
		// printf("@ %d %lld %lld - %lld\n",u,l,r,find(u));
		return find(u);
	}
	ll mid=(l+r)/2;
	if(pos<=mid) return getfa(ls[u],l,mid,pos);
	else return getfa(rs[u],mid+1,r,pos);
}
signed main()
{
	// cout<<sizeof(ls)/1024.0/1024.0<<endl;
	cin>>n>>Q; ful=(1ll<<n)-1;
	int cnt=0;
	for(int i=1;i<=Q;i++)
	{
		scanf("%s",_s+1);
		op[i]=_s[1]=='a';
		l[i]=read(),r[i]=read();
		if(op[i]==0) ins(rt,0,ful,l[i],r[i]),t[++cnt]=l[i],t[++cnt]=r[i];
	}
	if(cnt==0)
	{
		for(int i=1;i<=Q;i++) printf("%d\n",1);
		return 0;
	}
	sort(t+1,t+cnt+1);
	if(t[1]!=0) ins(rt,0,ful,0,t[1]-1);
	if(t[cnt]!=ful) ins(rt,0,ful,t[cnt]+1,ful);
	for(int i=2;i<=cnt;i+=2) if(t[i]+1<=t[i+1]-1) ins(rt,0,ful,t[i]+1,t[i+1]-1);
	if(t[1]!=0) fix(rt,0,ful,0,t[1]-1);
	if(t[cnt]!=ful) fix(rt,0,ful,t[cnt]+1,ful);
	for(int i=2;i<=cnt;i+=2) if(t[i]+1<=t[i+1]-1) fix(rt,0,ful,t[i]+1,t[i+1]-1);
	for(int i=Q;i>=1;i--)
	{
		// printf("--- %d\n",i);
		if(!op[i]) fix(rt,0,ful,l[i],r[i]);
		else ans[i]=getfa(rt,0,ful,l[i])==getfa(rt,0,ful,r[i]);
	}
	for(int i=1;i<=Q;i++) if(op[i]) printf("%d\n",ans[i]);
	return 0;
}