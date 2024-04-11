#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)
#define ll long long

const int N = 2e4;
const int TN = N << 2;

typedef pair<ll,ll> pll;
typedef vector<pll> cvx;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)x = -x,putchar('-');
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

struct cvxSegTree{
	cvx c[TN+5];
	int pos[TN+5];
	In bool check(pll a,pll b,pll c){
		return (c.first - b.first) * (b.second - a.second) 
		- (c.second - b.second) * (b.first - a.first) < 0;
	}
	void build(int u,int l,int r,ll pref[]){
		c[u].resize(0);
		pos[u] = 0;
		for(rg int i = l;i <= r;i++){
			while(c[u].size() > 1 && !check(c[u][c[u].size()-2],c[u][c[u].size()-1],make_pair(i,pref[i])))
				c[u].pop_back();
			c[u].push_back(make_pair(i,pref[i]));	
		}
//cout<<"build: u="<<u<<" l="<<l<<" r="<<r<<endl;
//for(auto x : c[u])cout<<"first="<<x.first<<" second="<<x.second<<endl;
		if(l == r)return;
		int m = (l + r) >> 1;
		build(glc(u),l,m,pref);
		build(grc(u),m + 1,r,pref);
	}
	int query(int u,int l,int r,int ql,int qr,ll k){
//cout<<"query: u="<<u<<" l="<<l<<" r="<<r<<" ql="<<ql<<" qr="<<qr<<" k="<<k<<endl;
		if(ql == l && qr == r){
			int i = pos[u];
			while(i + 1 < c[u].size() && c[u][i+1].second - k * c[u][i+1].first < c[u][i].second - k * c[u][i].first)i++;
			pos[u] = i;
			return c[u][i].second - k * c[u][i].first;
		}
		int m = (l + r) >> 1;
		if(qr <= m)return query(glc(u),l,m,ql,qr,k);
		else if(ql > m)return query(grc(u),m + 1,r,ql,qr,k);
		else return min(query(glc(u),l,m,ql,m,k),query(grc(u),m + 1,r,m + 1,qr,k));
	}
}S;

struct lcSegTree{
	ll k[TN+5],b[TN+5];
	In void init(){
		memset(k,0,sizeof(k));
		memset(b,0,sizeof(b));
	}
	In bool cmp(ll k,ll b,ll _k,ll _b,ll x){
		return k * x + b < _k * x + _b;
	}
	void set(int u,int l,int r,ll _k,ll _b){
//cout<<"set: u="<<u<<" l="<<l<<" r="<<r<<" _k="<<_k<<" _b="<<_b<<endl;
//cout<<"k[u]="<<k[u]<<" b[u]="<<b[u]<<endl;
		if(!k[u] && !b[u]){
			k[u] = _k,b[u] = _b;
			return;
		}
		int m = (l + r) >> 1;
		bool bl = cmp(_k,_b,k[u],b[u],l);
		bool bm = cmp(_k,_b,k[u],b[u],m);
		bool br = cmp(_k,_b,k[u],b[u],r);
//cout<<"bm="<<bm<<" bl="<<bl<<" br="<<br<<endl;
		if(!bl && !br)return;
		if(bl && br){
			k[u] = _k,b[u] = _b;
			return;
		}
		if(bl){
			if(bm){
				set(grc(u),m + 1,r,k[u],b[u]);
				k[u] = _k,b[u] = _b;
			}
			else set(glc(u),l,m,_k,_b);
		}
		else{
			if(bm){
				set(glc(u),l,m,k[u],b[u]);
				k[u] = _k,b[u] = _b;
			}
			else set(grc(u),m + 1,r,_k,_b);
		}
	}
	void insert(int u,int l,int r,int ql,int qr,ll _k,ll _b){
		if(l == ql && r == qr){
			set(u,l,r,_k,_b);
			return;
		}
		int m = (l + r) >> 1;
		if(qr <= m)insert(glc(u),l,m,ql,qr,_k,_b);
		else if(ql > m)insert(grc(u),m + 1,r,ql,qr,_k,_b);
		else insert(glc(u),l,m,ql,m,_k,_b),insert(grc(u),m + 1,r,m + 1,qr,_k,_b);
	}
	ll query(int u,int l,int r,ll x){
		ll ans;
		if(!k[u] && !b[u])ans = 4e8;
		else ans = k[u] * x + b[u];
		if(l == r)return ans;
		int m = (l + r) >> 1;
		if(x <= m)ans = min(ans,query(glc(u),l,m,x));
		else ans = min(ans,query(grc(u),m + 1,r,x));
		return ans;
	}
}T;

ll n,k;
ll a[N+5],f[N+5];
int p[N+5];

In bool cmp(int i,int j){
	return a[i] < a[j];
}

struct ST{
	ll maxn[N+5][18];
	int lg[N+5];
	void prepro(){
		for(rg int i = 2;i <= n;i++)lg[i] = lg[i>>1] + 1;
		for(rg int i = 1;i <= n;i++)maxn[i][0] = a[i];
		for(rg int j = 1;j <= 18;j++){
			for(rg int i = 1;i + (1 << j) - 1 <= n;i++){
				maxn[i][j] = max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
			}
		}
	}
	In int query(int l,int r){
		int d = lg[r-l+1];
		return max(maxn[l][d],maxn[r+1-(1<<d)][d]);
	}
}st;

void dp(){
	S.build(1,1,n,f);
	T.init();
	for(rg int i = 1;i <= n;i++)p[i] = i;
	sort(p + 1,p + n + 1,cmp);
	for(rg int j = 1;j <= n;j++){
		int i = p[j];
//cout<<"i="<<i<<endl;
		int L = 1,R = i;
		while(L < R){
			int mid = (L + R + 1) >> 1;
			if(st.query(mid,i) > a[i])L = mid;
			else R = mid - 1;
		}
//cout<<" L="<<L<<endl;
		if(L >= i)continue;
		ll g = S.query(1,1,n,L,i - 1,a[i]);
//cout<<"  g="<<g<<endl;
		
		L = i,R = n;
		while(L < R){
			int mid = (L + R + 1) >> 1;
			if(st.query(i,mid) > a[i])R = mid - 1;
			else L = mid;
		}
//cout<<" L="<<L<<endl;
		if(i <= L)T.insert(1,1,n,i,L,a[i],g);
//cout<<"insert segment: l="<<i<<" r="<<L<<" k="<<a[i]<<" b="<<g<<endl;
	}
	for(rg int i = 1;i <= n;i++)f[i] = T.query(1,1,n,i);
//for(rg int i = 1;i <= n;i++)cout<<f[i]<<" ";cout<<endl;
}

int main(){
//	freopen("CF1175G.in","r",stdin);
//	freopen("CF1175G.out","w",stdout);
//clock_t s = clock();
	n = read();k = read();
	for(rg int i = 1;i <= n;i++)a[i] = read();
	st.prepro();
	
	for(rg int i = 1;i <= n;i++)f[i] = max(f[i-1],a[i]);
	for(rg int i = 1;i <= n;i++)f[i] *= i;
	for(rg int i = 2;i <= k;i++){
		dp();
	}

	write(f[n]),putchar('\n');
//clock_t t = clock();
//cout<<"time="<<t-s<<endl;
//while(clock() - t < 1e8);
	return 0;
}