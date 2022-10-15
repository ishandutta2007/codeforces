// how to come up with such solution :(

// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
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
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=10000007;
const int K=207;
mt19937 rng(1234);

uint32_t b[N],x,y,z,b1,b2;
int a[N],mn[N];
int n,l,r;

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>l>>r>>x>>y>>z>>b1>>b2;
        b[1]=b1, b[2]=b2;
        for (int i=3;i<=n;++i) b[i]=b[i-2]*x+b[i-1]*y+z;
        for (int i=1;i<=n;++i) a[i]=((int)b[i])%(r-l+1)+l;
        mn[0]=INF;
        int ans=INF;
        for (int i=1;i<=n;++i){
            mn[i]=min(mn[i-1],a[i]);
        }
        for (int i=2;i<=n;++i){
            if (a[i]>=0&&mn[i-1]<0) ans=min(ans,a[i]*mn[i-1]);
        }
        if (ans!=INF){
            cout<<ans<<"\n";
            continue;
        }
        auto solve=[&](int L,int R){
            stack<int> st;
            for (int i=R;i>=L;--i){
                while (sz(st)&&a[st.top()]>=a[i]) st.pop();
                st.push(i);
            }
            vi b;
            while (sz(st)) b.pb(st.top()), st.pop();
            // for (auto c:b) cout<<c<<" ";
            // cout<<endl;
            for (int i=R;i>L;--i){
                int lb=*prev(lower_bound(range(b),i));
                if (a[lb]>=a[i]) continue;
                ans=min(ans,a[lb]*a[i]);
            }
        };
        int midx=n+1;
        for (int i=n;i>0;--i){
            if (a[i]<0) midx=i, a[i]=-a[i];
        } 
        if (midx>1) solve(1,midx-1);
        if (midx<=n) reverse(a+midx,a+n+1), solve(midx,n); 
        if (ans!=INF) cout<<ans<<"\n";
        else cout<<"IMPOSSIBLE\n";
    }
    
    return 0;
}

/*
1
10000000 -2000000000 2000000000 123 321 12312312312 123123123
*/