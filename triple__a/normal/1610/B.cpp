// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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

int n;
int a[maxn];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        rep(i,n) cin>>a[i];
        auto check=[&](int u){
            vi ret;
            ret.clear();
            rep(i,n){
                if (a[i]!=u) ret.pb(a[i]);
            }
            int m=sz(ret);
            rep(i,m) if (ret[i]!=ret[m-1-i]) return false;
            return true;
        };
        int idx=-1;
        for (int i=0;i<n;++i){
            if (a[i]!=a[n-i-1]) {idx=i; break;}
        }
        if (idx==-1){
            cout<<"YES\n";
        }
        else{
            if (check(a[idx])||check(a[n-1-idx])) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0; 
}

/*
1
5
7 7
5 6
-9 0
6 -1
-1 3
1
2
-4 9
-2 5
*/