//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;

#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
/* 
u^v % mod
*/
ll power(ll u,ll v,ll mod){
    ll ret=1,t=u%mod;
    while (v){
        if (v&1) ret=t*ret%mod;
        t=t*t%mod, v>>=1;
    }
    return ret%mod;
}
 
/*
gcd(a,b)ax+by=gcd(a,b)
ret=exgcd(a,b,x,y); 
*/
ll exgcd(ll a,ll b,ll &x,ll &y){
    if (b){
        ll d=exgcd(b,a%b,y,x);
        return y-=a/b*x, d;
    }
    return x=1,y=0,a;
}
 
/*
x=a(mod m), x=b(mod n)-1
ret=crt(a,m,b,n);
*/
ll crt(ll a,ll m,ll b,ll n){
    if (n>m) swap(a,b), swap(n,m);
    ll x,y,g=exgcd(m,n,x,y);
    if ((b-a)%g) return -1;
    x=(b-a)%n*x%n/g*m+a;
    return x<0?x+m*n/g:x;
}
 
/*
<=n
gen_prime<5000>(ret);
*/
 
void gen_prime(int n,vi &ret){
    vector<bool> p;
    p.resize(n+1,1);
    p[0]=p[1]=0;
    for (int i=4;i<=n;i+=2) p[i]=0;
    for (int i=3;i*i<=n;i+=2){
        if (p[i]){
            for (int j=i*i;j<=n;j+=2*i){
                p[j]=0;
            }
        }
    }
    for (int i=2;i<=n;++i){
        if (p[i]) ret.pb(i);
    }
}
 
/*
<=nphi
gen_phi<5000>(ret);
*/
void gen_phi(int n,vi &phi){
    phi.resize(n+1);
    for (int i=0;i<=n;++i) phi[i]=i&1?i:i/2;
    for (int i=3;i<=n;i+=2){
        if (phi[i]==i){
            for (int j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
        }
    }
}
 
/*

expower.mod_pow(a,b,mod);
*/
 
struct expower{
    ull mod_mul(ull a,ull b,ull M) {
        ll ret=a*b-M*ull(ld(a)* ld(b)/ld(M));
        return ret+M*(ret<0)-M*(ret>=(ll)M);
    }
    ull mod_pow(ull b,ull e,ull mod) {
        ull ans=1;
        for (; e; b=mod_mul(b,b,mod), e/=2)
            if (e&1) ans=mod_mul(ans,b,mod);
        return ans%mod;
    }
}expower;
 
/*
Miller-Rubin
is_prime(n);
*/
bool is_prime(ull n){ 
    if (n<2||n%6%4!=1) return n-2<2;
    ull A[]={2,325,9375,28178,450775,9780504,1795265022},
    s=__builtin_ctzll(n-1), d = n >> s;
    for (auto a:A){
        ull p=expower.mod_pow(a,d,n),i=s;
        while (p!=1&&p!=n-1&&a%n&&i--)
            p=expower.mod_mul(p,p,n);
        if (p!=n-1&&i!=s) return 0;
    }
    return 1;
}
 
/*

ret=factorization(n);
*/
ull pollard(ull n){
    auto f=[n](ull x){return (expower.mod_mul(x,x,n)+1)%n;};
    if (!(n&1)) return 2;
    for (ull i=2;;i++){
        ull x=i,y=f(x),p;
        while ((p=__gcd(n+y-x,n))==1)
            x=f(x),y=f(f(y));
        if (p!=n) return p;
    }
}
 
vector<ull> factorization(ull n){
    if (n==1) return {};
    if (is_prime(n)) return {n};
    ull x=pollard(n);
    auto l=factorization(x),r=factorization(n/x);
    l.insert(l.end(),range(r));
    return l;
}
 
struct DSU{
    //insert info.
    vector<int> p;
    DSU(int n){
        p.resize(n+1);
        for (int i=1;i<=n;++i) p[i]=i;
    }
    int find(int u){
        if (p[u]==u) return u;
        return p[u]=find(find(p[u]));
    } 
    bool unite(int u,int v){
        int pu=find(u), pv=find(v);
        if (pu!=pv){
            p[pu]=pv;
        }
        return pu!=pv;
    }
};
 
/* (u,v,w) */
template<class T> vector<tuple<int,int,T> > MST(int n,vector<tuple<int,int,T> >g){
    vector<tuple<int,int,T> > ret;
    ret.clear();
    DSU dsu(n);
    auto cmp=[&](tuple<int,int,T> x,tuple<int,int,T> y){
        int ux,uy,vx,vy;
        T wx,wy;
        tie(ux,vx,wx)=x, tie(uy,vy,wy)=y;
        return wx<wy;
    };
    sort(range(g),cmp);
    for (auto c:g){
        int u,v;
        T w;
        tie(u,v,w)=c;
        if(dsu.unite(u,v)) ret.push_back(c);
    }
    return ret;
}
 
template<int n,class T>
struct SegmentTree{
    typedef struct{
        T lz,mx,mn,sum;
    }Node;
    vector<Node> tree;
    SegmentTree(){
        tree.resize((n+7)<<2);
    }  
    void pushup(int num){
        tree[num].mx=max(tree[num<<1].mx,tree[num<<1|1].mx);
        tree[num].mn=min(tree[num<<1].mn,tree[num<<1|1].mn);
        tree[num].sum=tree[num<<1].sum+tree[num<<1|1].sum;
    }
    void pushdown(int num,int l,int r,int md){
        if (tree[num].lz){
            tree[num<<1].mx+=tree[num].lz;
            tree[num<<1|1].mx+=tree[num].lz;
            tree[num<<1].mn+=tree[num].lz;
            tree[num<<1|1].mn+=tree[num].lz;
            tree[num<<1].sum+=tree[num].lz*(md-l+1);
            tree[num<<1|1].sum+=tree[num].lz*(r-md);
            tree[num<<1].lz+=tree[num].lz;
            tree[num<<1|1].lz+=tree[num].lz;
            tree[num].lz=0;
        }
    }
    void update1(int num,int l,int r,int L,int R,T val){
        if (L<=l&&r<=R){
            tree[num].mx+=val;
            tree[num].mn+=val;
            tree[num].sum+=val*(r-l+1);
            tree[num].lz+=val;
            return;
        }
        int md=(l+r)>>1;
        pushdown(num,l,r,md);
        if (md>=L) update1(num<<1,l,md,L,R,val);
        if (md<R) update1(num<<1|1,md+1,r,L,R,val);
        pushup(num);
    }
    tuple<T,T,T> query1(int num,int l,int r,int L,int R){
        if (L<=l&&r<=R){
            return {tree[num].mn,tree[num].mx,tree[num].sum};
        }
        int md=(l+r)>>1;
        pushdown(num,l,r,md);
        if (md>=R){
            return query1(num<<1,l,md,L,R);
        }
        else{
            if (md<L){
                return query1(num<<1|1,md+1,r,L,R);
            }
            else{
                tuple<T,T,T> ret1=query1(num<<1,l,md,L,R), ret2=query1(num<<1|1,md+1,r,L,R);
                T a,b,c,d,e,f;
                tie(a,b,c)=ret1, tie(d,e,f)=ret2;
                return {min(a,d),max(b,e),c+f};
            }
        } 
    }
    void update(int L,int R,int w){
        update1(1,1,n,L,R,w);
    }
    tuple<T,T,T> query(int L,int R){
        return query1(1,1,n,L,R);
    }
    void debug1(int num,int l,int r){
        if (l==r){
            cout<<tree[num].mn<<" "; return;
        }
        int md=(l+r)>>1;
        pushdown(num,l,r,md);
        debug1(num<<1,l,md);
         debug1(num<<1|1,md+1,r);        
    }
    void debug(){
        debug1(1,1,n);
        cout<<endl;
    }
};
 
struct XORBasis{
    int n;
    vector<ull> p;
    vector<ull> ans;
    XORBasis(int k):n(k){
        p.resize(k+1);
    }
    void rebuilt(){
        ans.clear();
        for (int i=0;i<=n;++i){
            if (p[i]) ans.push_back(p[i]);
        }
    }
    void insert(ull u){
        for (int i=n;i>=0;--i){
            if (u&(1ull<<i)){
                if (p[i]) u^=p[i];
                else{
                    p[i]=u;
                    for (int j=i-1;j>=0;--j){
                        if (p[i]&(1ull<<j)) p[i]^=p[j];
                    }
                    for (int j=i+1;j<=n;++j){
                        if (p[j]&(1ull<<i)) p[j]^=p[i];
                    }
                    break;
                }
            }
        }
        rebuilt();
    }
    ull kth(ull t){ // the k-th smallest, excluding 0.
        if (t>=(1ull<<sz(ans))) return -1;
        ull ret=0;
        for (int i=0;i<sz(ans);++i){
            if (t&(1ull<<i)) ret^=ans[i];
        }
        return ret;
    }
    ull total(){
        return (1ull<<sz(ans));
    }
};
 

vi pi(const string& s) {
	vi p(sz(s));
	for (int i=1;i<=sz(s);++i) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	for(int i=sz(p)-sz(s);i<=sz(p);++i)
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}


struct AhoCorasick {
	enum {alpha = 26, first = 'a'};
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1;
        ll nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vector<int> backp;
	void insert(string& s, int j,ll val) {
		assert(!s.empty());
		int n = 0;
		for(auto c:s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches+=val;
	}
	AhoCorasick(vector<string>& pat,vi val) {
		N.emplace_back(-1);
		for (int i=0;i<sz(pat);++i) insert(pat[i], i, val[i]);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			for (int i=0;i<alpha;++i) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vi find(string& word,ll& ans) {
		int n = 0;
		vi res;
		for(auto c:word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			ans += N[n].nmatches;
		}
		return res;
	}
	vector<vi> findAll(vector<string>& pat, string word) {
		ll ans=0;
        vi r = find(word,ans);
		vector<vi> res(sz(word));
		for (int i=0;i<sz(word);++i) {
			int ind = r[i];
			while (ind != -1) {
				res[i - sz(pat[ind]) + 1].push_back(ind);
				ind = backp[ind];
			}
		}
		return res;
	}
};

struct HLD{
    int n,cnt=0;
    vector<vi> G;
    vi par,dep,siz,son,top,dfn,rk; 
    //dfsdfs
    HLD(vector<vi> g,int root=1):n(sz(g)),G(g),par(n+7),dep(n+7),siz(n+7,1),son(n+7,-1),top(n+7),dfn(n+7),rk(n+7){
        dep[0]=-1, dfs1(root,0), dfs2(root,0,root);
    }
    void dfs1(int u,int p){
        for (auto c:G[u]){
            if (c==p) continue;
            dep[c]=dep[u]+1, par[c]=u;
            dfs1(c,u);
            siz[u]+=siz[c];
            if (son[u]==-1||siz[son[u]]<siz[c]) son[u]=c;
        }
    }
    void dfs2(int u,int p,int tp){
        top[u]=tp;
        dfn[u]=++cnt;
        rk[cnt]=u;
        if (son[u]==-1) return;
        dfs2(son[u],u,tp);
        for (auto c:G[u]){
            if (c==p||c==son[u]) continue;
            dfs2(c,u,c);
        }
    }
    int lca(int u,int v){
        while (top[u]!=top[v]){
            if (dep[top[u]]>dep[top[v]]){
                u=par[top[u]];
            }
            else{
                v=par[top[v]];
            }
        }
        return dep[u]>dep[v]?v:u;
    }
    vector<pii> find_seg(int u,int v){
        vector<pii> ft,bk,res;
        ft.clear(), bk.clear(), res.clear();
//        cout<<top[u]<<" "<<top[v]<<endl;
        while (top[u]!=top[v]){
            if (dep[top[u]]>dep[top[v]]){
                ft.pb({u,top[u]});
                u=par[top[u]];
            }
            else{
                bk.pb({top[v],v});
                v=par[top[v]];
            }
        }
        ft.pb({u,v});
        for (int i=0;i<sz(ft);++i) res.pb(ft[i]);
        for (int i=sz(bk);i>0;--i) res.pb(bk[i-1]);
        return res;
    }
};
int t;
int a,b,c,d;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	cin>>t;
	while (t--){
		cin>>a>>b>>c>>d;
		d=min(d,2*c);
		if (a<0) a=-a,b=-b;
		if (b<0){
			cout<<(a-b)*c<<" ";
		}
		else{
			cout<<d*min(a,b)+c*(max(a,b)-min(a,b))<<" ";
		}
	}
    return 0;
}