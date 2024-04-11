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
// const int mod=998244353;
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=100007;
const int K=19;
mt19937 rng(1234);

const int mod[2]={998244353,234567899};
const int base[2]={12321,32123};
int n;
string a,b;
int aa[N],bb[N];
int diff[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>a>>b;
    rep(i,n) aa[i]=a[i]-'0', bb[i]=b[i]-'0';
    rep1(i,n){
        int now=aa[i-1]+diff[i-1], targ=bb[i-1];
        diff[i]=targ-now;
    }
    if (diff[n]){
        cout<<"-1\n";
        return 0;
    }
    set<int> s;
    auto upd=[&](int i){
        if (i<=0||i>=n) return;
        if (!diff[i]) return;
        if (diff[i]>0&&aa[i-1]<9&&aa[i]<9) s.insert(i);
        if (diff[i]<0&&aa[i-1]>(i-1?0:1)&&aa[i]>0) s.insert(i);
    };
    int sum=0;
    for (int i=1;i<=n-1;++i) sum+=abs(diff[i]);
    for (int i=1;i<=n-1;++i){
        upd(i);
    }
    vector<pii> ans;
    while (sz(s)&&sz(ans)<1e5){
        auto ret=*s.begin();
        if (diff[ret]>0){
            ans.pb({ret-1,1});
            diff[ret]--, aa[ret-1]++, aa[ret]++;
        }
        else{
            ans.pb({ret-1,-1});
            diff[ret]++, aa[ret-1]--, aa[ret]--;
        }
        s.erase(ret), s.erase(ret-1), s.erase(ret+1);
        upd(ret-1), upd(ret), upd(ret+1);
    }
    cout<<sum<<"\n";
    for (auto c:ans) cout<<c.F+1<<" "<<c.S<<"\n";
    return 0;
}

/*
3
3 3
3 1 5
7 5
5 5 5 4 1 2 1
2 10
3 3
*/