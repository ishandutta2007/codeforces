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
const int N=500007;
const int K=19;
mt19937 rng(1234);

int m,k,n,s;
int a[N],b[N],cnt[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>m>>k>>n>>s;
    rep(i,m) cin>>a[i];
    rep(i,s) cin>>b[i];
    int pos=0;
    rep(i,s) cnt[b[i]]++;
    int fk=0;
    rep1(i,500000) if (cnt[i]) fk++;
    for (int i=0;i<m;i+=k){
        while (pos<m){
            if (fk==0&&pos-i>=k) break;
            cnt[a[pos]]--;
            if (!cnt[a[pos]]) fk--;
            pos++;
            if (fk==0&&pos-i>=k) break;
        }
        if (!fk&&pos-i>=k&&i/k+(m-pos)/k+1>=n){
            memset(cnt,0,sizeof(cnt));
            rep(j,s) cnt[b[j]]++;
            vi ans; 
            for (int j=i;j<pos;++j){
                if (cnt[a[j]]) cnt[a[j]]--;
                else ans.pb(j);
            }
            for (int j=0;j<k-s;++j) ans.pop_back();
            cout<<sz(ans)<<"\n";
            for (auto c:ans) cout<<c+1<<" ";
            cout<<"\n";
            return 0;
        }
        for (int j=i;j<min(i+k,m);++j) {
            cnt[a[j]]++;
            if (cnt[a[j]]==1) fk++;
        }
        if (pos==m) break;
    }
    cout<<"-1";
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