// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
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
 
 
const int maxn=200007;
const int mod=998244353;
const double pi=3.1415926535;

int n,k;
int a[maxn],b[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i];
        sort(a,a+n), sort(b,b+n);
        bool ok=1;
        rep(i,n){
            if (a[i]>b[i]) ok=0;
            if (a[i]+1<b[i]) ok=0;
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}