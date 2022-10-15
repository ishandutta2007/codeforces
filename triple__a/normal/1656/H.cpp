// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
#define int long long
#define i128 __int128_t
#define double long double
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
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=1007;
const int K=18;
mt19937 rng(time(NULL));

int n,m;
i128 res,a[N],b[N];
bool alive[2][N];
i128 lcm(i128 u,i128 v){
    return u/__gcd(u,v)*v;
}
struct seg{
    i128 seg[N<<2];
    void build(int num,int l,int r){
        seg[num]=1;
        if (l==r) return;
        int md=(l+r)>>1;
        build(num<<1,l,md);
        build(num<<1|1,md+1,r);
    }
    void pushup(int num){
        seg[num]=lcm(seg[num<<1],seg[num<<1|1]);
    }
    void update(int num,int l,int r,int x,i128 val){
        if (l==r) {seg[num]=val; return;}
        int md=(l+r)>>1;
        if (x<=md) update(num<<1,l,md,x,val);
        else update(num<<1|1,md+1,r,x,val);
        pushup(num);
    }
};

void scan(i128& x) {
	static char s[55];
	std::cin >> s;
	x = 0;
	for (char *c = s; *c; ++c) x = x * 10 + *c - '0';
}

void out(i128 t){
    vi ans;
    while (t){
        ans.pb(t%10), t/=10;
    }    
    reverse(range(ans));
    for (auto c:ans) cout<<c;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>m;
        rep1(i,n) scan(a[i]);
        rep1(i,m) scan(b[i]);
        vector<seg> A(n+1), B(m+1);
        rep1(i,n) A[i].build(1,1,m);
        rep1(i,m) B[i].build(1,1,n);
        rep1(i,n) rep1(j,m) A[i].update(1,1,m,j,__gcd(a[i],b[j]));
        rep1(i,m) rep1(j,n) B[i].update(1,1,n,j,__gcd(a[j],b[i]));
        rep1(i,n) alive[0][i]=1;
        rep1(i,m) alive[1][i]=1;
        while (1){
            auto fnd=[&]()->pii{
                rep1(i,n) {
                    if (!alive[0][i]) continue;
                    if (A[i].seg[1]==a[i]) continue;
                    alive[0][i]=0;
                    rep1(j,m) B[j].update(1,1,n,i,1);
                    return {0,i}; 
                }
                rep1(i,m){
                    if (!alive[1][i]) continue;
                    if (B[i].seg[1]==b[i]) continue;
                    alive[1][i]=0;
                    rep1(j,n) A[j].update(1,1,m,i,1);
                    return {0,i};
                }
                return {-1,0};
            };
            auto ret=fnd();
            if (ret.F==-1) break;
        }
        vector<i128> X,Y;
        rep1(i,n) if (alive[0][i]) X.pb(a[i]);
        rep1(i,m) if (alive[1][i]) Y.pb(b[i]);
        if (!sz(X)||!sz(Y)){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<sz(X)<<" "<<sz(Y)<<"\n";
            for (auto c:X) out(c), cout<<" ";
            cout<<"\n";
            for (auto c:Y) out(c), cout<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


/*
10

*/