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
const int mod=1e9+7;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=100007;
const int K=207;
mt19937 rng(time(NULL));

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        int n;
        cin>>n;
        auto query=[&](vi &l, vi&r){
            cout<<sz(l)<<" "<<sz(r)<<" ";
            for (auto c:l) cout<<c<<" ";
            for (auto c:r) cout<<c<<" ";
            cout<<endl;
            int u;
            cin>>u;
            return u;
        };
        vi sig,all;
        sig.pb(n);
        for (int i=1;i<n;++i) all.pb(i);
        auto mxdist=query(sig,all);
        for (int i=0;i<8;++i){
            vi test,other;
            for (auto c:all){
                if (c>>i&1) test.pb(c);
                else other.pb(c);
            }
            if (sz(test)==0) continue;
            auto ret=query(sig,test);
            if (ret<mxdist) all=other;
            else all=test;
        }
        assert(sz(all)==1);
        sig.clear();
        for (int i=1;i<=n;++i) if (i!=all[0]) sig.pb(i);
        auto ans=query(sig,all);
        cout<<"-1 "<<ans<<endl;
    }
    return 0;
}


/*
5 3
1 2
2 3
3 4
4 5


*/