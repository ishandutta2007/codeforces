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
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=998244353;
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=100007;
const int K=207;
mt19937 rng(1234);

int n,m;
int sz[N], rem[N], p[N];
vi cont[N];
set<int> need;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>m;
    int sum=0;
    rep1(i,n){
        cin>>sz[i];
        sum+=sz[i];
        rep(j,sz[i]){
            int u;
            cin>>u;
            cont[u].pb(i);
        }
        p[i]=i;
    }
    sort(p+1,p+n+1,[&](int u,int v){return sz[u]>sz[v];});
    for (int i=0;i<n;++i){
        int targ=sum/n+(i<sum%n?1:0);
        rem[p[i+1]]=sz[p[i+1]]-targ;
    }
    int summ=0;
    rep1(i,n) summ+=abs(rem[i]);
    cout<<summ/2<<"\n";
    rep1(i,n) if (rem[i]<0) need.insert(i);
    for (int i=1;i<=m;++i){
        vi L,R,ok;
        for (auto c:cont[i]){
            if (rem[c]<0) need.erase(c), L.pb(c);
            if (rem[c]>0) R.pb(c);
        }
        for (auto c:need){
            if (!sz(R)) break;
            int idx=R.back();
            rem[idx]--, rem[c]++;
            R.pop_back();
            cout<<idx<<" "<<c<<" "<<i<<"\n";
            if (!rem[c]) ok.pb(c);
        }
        for (auto c:L) need.insert(c);
        for (auto c:ok) need.erase(c);
    }
    for (int i=1;i<=n;++i) assert(rem[i]==0);
    return 0;
}

/*
3 5
5 1 2 3 4 5
2 1 2
2 3 4
*/