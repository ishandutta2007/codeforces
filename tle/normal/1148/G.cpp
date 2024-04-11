#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n,k,a[SZ];
ll rb()
{
	ll t=0;
	for(int j=0;j<4;++j)
		t=t*(RAND_MAX)+rand();
	return t&((1LL<<62)-1);
}
#define MOD 30000001
#define SS 25700077
struct my_hash_table{
	int h[MOD],nxt[SS],vv[SS],ec; ll fl[SS];
	int &operator[](ll v){
		for(int e=h[v%MOD];e;e=nxt[e])if(fl[e]==v)return vv[e];
		++ec,fl[ec]=v,nxt[ec]=h[v%MOD],h[v%MOD]=ec;
		vv[ec]=0; return vv[ec];
	}
	void clear()
	{
		for(int i=1;i<=ec;++i) h[fl[i]%MOD]=0;
		ec=0;
	}
}tt;
#undef MOD
int an=0,aa[SZ];
vector<int> P,U[100055];
ll xo[SS],tp[SZ];
int ts[SZ],tn,fa[SZ];
void go(int l,int r,vector<int> v)
{
	if(!v.size()) return;
	if(l==r)
	{
		for(auto s:v) fa[s]=ts[l];
		return;
	}
	int m=(l+r)>>1; ll ttt=0;
	for(int s=l;s<=m;++s)
	{
		ll R=rb(); tp[s]=R; ttt^=R;
		for(auto p:U[ts[s]]) xo[p]^=R;
	}
	vector<int> L,R;
	for(auto s:v)
	{
		ll vv=0;
		for(auto p:U[s]) vv^=xo[p];
		if(vv==ttt) R.pb(s);
		else L.pb(s);
	}
	v.clear();
	for(int s=l;s<=m;++s)
		for(auto p:U[ts[s]]) xo[p]^=tp[s];
	go(l,m,L); go(m+1,r,R);
}
int out[SZ];
vector<int> ch[SZ];
bool by_sch(int x,int y) {return ch[x].size()>ch[y].size();}
int main()
{
	srand(time(0)^1231313^chrono::steady_clock::now().time_since_epoch().count());
	for(int i=2;i<=10000;++i)
	{
		bool np=0;
		for(int j=2;j*j<=i;++j) if(i%j==0) np=1;
		if(!np) P.pb(i);
	}
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i); aa[i]=a[i];
		vector<int> p;
		for(auto j:P)
		{
			if(j*j>a[i]) break;
			if(a[i]%j) continue;
			p.pb(j);
			while(a[i]%j==0) a[i]/=j;
		}
		if(a[i]>1) p.pb(a[i]);
		sort(p.begin(),p.end());
		int s=p.size();
		U[i].resize((1<<s)-1);
		for(int u=1;u<(1<<s);++u)
		{
			ll kk=1;
			for(int w=0;w<s;++w) if(u&(1<<w))
				kk=kk*10000007+p[w];
			kk&=((1LL<<62)-1);
			auto&w=tt[kk];
			if(!w) w=++an;
			U[i][u-1]=w;
		}
	}
	vector<int> u;
	ll ttt=0;
	for(int i=1;i<=n;++i)
	{
		ll xw=0;
		for(auto p:U[i])
			xw^=xo[p];
		if(xw==ttt)
		{
			ll R=rb();
			for(auto p:U[i]) xo[p]^=R;
			ttt^=R;
			ts[++tn]=i;
		}
		else u.pb(i),out[i]=1;
	}
	for(int i=1;i<=n;++i)
		for(auto p:U[i]) xo[p]=0;
	if(tn>=k)
	{
		for(int i=1;i<=k;++i)
			printf("%d ",ts[i]);
		return 0;
	}
	go(1,tn,u);
	for(auto p:u)
	{
		assert(__gcd(aa[p],aa[fa[p]])==1);
		ch[fa[p]].pb(p);
	}
	vector<int> t,op;
	for(int i=1;i<=tn;++i) t.pb(ts[i]);
	sort(t.begin(),t.end(),by_sch);
	for(auto r:t) if(ch[r].size()&&op.size()+2<=k)
	{
		op.pb(r);
		op.pb(ch[r].back());
		ch[r].pop_back();
	}
	for(auto r:t)
	{
		while(op.size()<k&&ch[r].size())
		{
			op.pb(ch[r].back()),
			ch[r].pop_back();
		}
	}
	assert(op.size()>=k);
	op.resize(k);
	for(auto t:op) printf("%d ",t);
}