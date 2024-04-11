#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define fi first
#define se second

const int N = 2e5;
const ll mod = 998244353;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

namespace ModCalc{
	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}
	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}
	In ll Add(ll x,ll y){Inc(x,y);return x;}
	In ll Sub(ll x,ll y){Dec(x,y);return x;}
};
using namespace ModCalc;

struct FHQTreap{
	int cnt,rt;
	int lc[N+5],rc[N+5],sz[N+5];
	ll val[N+5],pri[N+5];
	In void clear(){cnt = rt = 0;}
	In int newnode(ll v){
		cnt++;
		val[cnt] = v;
		pri[cnt] = 1ll * rand() * 19709 % 998244353;
		lc[cnt] = rc[cnt] = 0;
		sz[cnt] = 1;
		return cnt;
	}
	In void pushup(int u){
		sz[u] = sz[lc[u]] + sz[rc[u]] + 1;
	}
	In int merge(int u,int v){
		if(!u || !v)return u + v;	
		if(pri[u] > pri[v]){
			rc[u] = merge(rc[u],v);
			pushup(u);
			return u;
		}
		else{
			lc[v] = merge(u,lc[v]);
			pushup(v);
			return v;
		}
	}
	In void split(int u,int &v,int &w,ll x){
		if(!u){v = w = 0;}
		else{
			if(val[u] <= x){
				v = u;
				split(rc[u],rc[v],w,x);
				pushup(v);
			}		
			else{
				w = u;
				split(lc[u],v,lc[w],x);
				pushup(w);
			}	
		}
	}
void print(int u){
	cout<<"u="<<u<<" lc="<<lc[u]<<" rc="<<rc[u]<<" val="<<val[u]<<" pri="<<pri[u]<<" sz="<<sz[u]<<endl;
	if(lc[u])print(lc[u]);
	if(rc[u])print(rc[u]);
}
	In void insert(ll x){
		int u,v;
		split(rt,u,v,x);
		rt = merge(merge(u,newnode(x)),v);
	}
	In int query(ll x){ // how many elements > x
		int u,v;
		split(rt,u,v,x);
		int ans = sz[v];
		rt = merge(u,v);
		return ans;
	}
};

struct Set{
	ll flag; // all elements in s += flag
	FHQTreap s;
	In void Init(){s.clear();flag = 0;}
	In void Insert(ll x){s.insert(x - flag);}
	In void Ud(ll x){ // all elements in s += x
		flag += x;
	}
	In ll Query(ll x){ // how many elements > x
		return s.query(x - flag);
	}
}T[2];

ll n,a[N+5];
ll pre[N+5],suf[N+5],pr[N+5][2],sf[N+5][2];

ll solve1(){ // !pp,!cc
	ll rt = 0;
	if(sf[1][0] - sf[1][1] > 0)rt++;
	if(sf[1][1] - sf[1][0] > 0)rt++;
	return rt;
}
ll solve2(){ // cc,!pp
	ll rt = 0;
	rep(i,1,n){
		if(i >= 2 && -pre[i] +            sf[i+1][(i+1)&1] - sf[i+1][i&1] > 0)rt++;
		if(i >= 3 && -pre[i] + 2 * a[1] + sf[i+1][(i+1)&1] - sf[i+1][i&1] > 0)rt++;
	}
	return rt;
}
ll solve3(){ // pp,!cc
	ll rt = 0;
	dwn(i,n,1){
		if(n - i >= 1 && suf[i] - 			 pr[i-1][(i-1)&1] + pr[i-1][i&1] > 0)rt++;
		if(n - i >= 2 && suf[i] - 2 * a[n] - pr[i-1][(i-1)&1] + pr[i-1][i&1] > 0)rt++;
	}
	return rt;
}
ll query4(ll p){ 
	ll rt = 0;
	if(n - p >= 2)Inc(rt,T[p&1].Query(-suf[p+1])); // ...pp..p
	if(n - p >= 3)Inc(rt,T[p&1].Query(-suf[p+1]+2*a[n])); // ...pp..pc
//cout<<"query4: p="<<p<<" rt="<<rt<<endl;
	return rt;
}
ll solve4(){ // pp,cc
	ll rt = 0;
	for(rg int p = 2;n - p >= 2;p++)if(pre[p] - suf[p+1] > 0)rt++; // pp..pcc..c
//cout<<rt<<endl;
	T[0].Init();T[1].Init();
	T[0].Insert(-a[1] - a[2]);   Inc(rt,query4(2)); // cc..
	T[1].Insert(-a[2]-a[3]+a[1]);					// pcc..
	T[1].Insert(-a[1]-a[2]-a[3]);Inc(rt,query4(3)); // ccc..
	rep(p,4,n){
		T[p&1].Ud(a[p-1] - a[p]); // add pc to back
		T[p&1].Insert(-pre[p]); // cc..c...
		T[p&1].Insert(-pre[p] + 2 * a[1]); // pcc.cc...
		Inc(rt,query4(p));
	}
	return rt;
}
void solve(){
	n = read();rep(i,1,n)a[i] = read();

	pre[0] = pr[0][0] = pr[0][1] = 0;
	rep(i,1,n){
		pre[i] = pre[i-1] + a[i];
		pr[i][  i&1 ] = pr[i-1][  i&1 ] + a[i];
		pr[i][!(i&1)] = pr[i-1][!(i&1)];
	}

	suf[n+1] = sf[n+1][0] = sf[n+1][1] = 0;
	dwn(i,n,1){
		suf[i] = suf[i+1] + a[i];
		sf[i][  i&1 ] = sf[i+1][  i&1 ] + a[i];
		sf[i][!(i&1)] = sf[i+1][!(i&1)];
	}
	
	ll ans = 0;
//cout<<"solve1="<<solve1()<<endl;
//cout<<"solve2="<<solve2()<<endl;
//cout<<"solve3="<<solve3()<<endl;
//cout<<"solve4="<<solve4()<<endl;
	Inc(ans,solve1());
	Inc(ans,solve2());
	Inc(ans,solve3());
	Inc(ans,solve4());
	write(ans),putchar('\n');
}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
// USE LONG LONG
// MULTIPLE CASES
	int Tc = read();
	while(Tc--)solve();
	return 0;
}
// T: Think
// E: Enough array size
// M: Memory limit
// P: Precision
// B: Boundary
// O: Overflow
// T: Time limit
// M: Mod
// F: File