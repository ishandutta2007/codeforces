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
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int MAXN=500007;
const int N=500007;
const int K=360*10000;
mt19937 rng(1234);

int n,k;
string s;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>s;
        // reverse(range(s));
        if (s[sz(s)-1]=='A'){
            cout<<"NO\n";
            continue;
        }
        int sum=0;
        bool ok=1;
        for (auto c:s){
            if (c=='A') sum++;
            else sum--;
            if (sum<0){
                ok=0;
            }
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}