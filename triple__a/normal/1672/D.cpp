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
#define Fi first
#define Se second

typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=1e9+7;
const int INF=LLONG_MAX/5000;
const double EPS=1e-9;
// const int MAXN=2003*2003;
const int N=2003*2003;
const int K=360*10000;
mt19937 rng(1234);

int n,k;
int a[N],b[N];

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    // _=1;
    while (_--){
        cin>>n;
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i];
        map<int,int> rem;
        int now=0;
        for (int i=0;i<n;++i){
            if (a[i]==b[now]) {
                now++;
                while (b[now]==b[now-1]&&rem[b[now]]){
                    rem[b[now]]--; now++;
                } 
                continue;
            }
            rem[a[i]]++;
        }
        if (now==n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}