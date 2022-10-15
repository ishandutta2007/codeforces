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

// using namespace std;

const int maxn=1000007;

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

int n,q;
int p[maxn],a[maxn];
vi prm;
vi idx[maxn];
int re[1000007];
// int qrx[2*maxn],qry[2*maxn];
// int ans[2*maxn];
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

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(find(p[u]));
} 
bool unite(int u,int v){
    int pu=find(u), pv=find(v);
    if (pu!=pv){
        p[pu]=pv;
            // sz[pv]+=sz[pu];
    }
    return pu!=pv;
}
set<pii> res;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    gen_prime(1000000,prm);
    memset(re,-1,sizeof(re));
    rep(i,sz(prm)) re[prm[i]]=i;
    rep(i,sz(prm)) idx[i].clear();
    rep(i,n) cin>>a[i], p[i]=i;
    rep(i,n){
        int u=a[i];
        while (u>1&&!is_prime(u)){
            int p=pollard(u);
            while (!is_prime(p)) p=pollard(p);
            idx[re[p]].pb(i);
            while (u%p==0) u/=p;
        }
        if (u>1) idx[re[u]].pb(i);
    }
    rep(i,sz(prm)){
        rep(j,sz(idx[i])-1){
            unite(idx[i][j],idx[i][j+1]);
        }
    }
    rep(i,n){
        int u=a[i]+1;
        vi hi;
        hi.clear();
        while (u>1&&!is_prime(u)){
            int p=pollard(u);
            while (!is_prime(p)) p=pollard(p);
            hi.pb(p);
            while (u%p==0) u/=p;
        }
        if (u>1) hi.pb(u);
        // for (auto c:hi) cout<<c<<" ";
        // cout<<endl;
        rep(j,sz(hi)){
            if (sz(idx[re[hi[j]]])) res.insert({find(idx[re[hi[j]]][0]),find(i)}),res.insert({find(i),find(idx[re[hi[j]]][0])});
        }
        rep(j,sz(hi)) rep(k,j){
            if (sz(idx[re[hi[j]]])&&sz(idx[re[hi[k]]])) res.insert({find(idx[re[hi[j]]][0]),find(idx[re[hi[k]]][0])}), res.insert({find(idx[re[hi[k]]][0]),find(idx[re[hi[j]]][0])});
        }
    }
    rep(i,q) {
        int x,y;
        cin>>x>>y; x--, y--;
        int px=find(x), py=find(y);
        if (px==py){
            cout<<"0\n";
            continue;
        }
        if (res.find({px,py})!=res.end()){
            cout<<"1\n";
        }
        else cout<<"2\n";
    }

    return 0;
}