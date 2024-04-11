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
int a[maxn],b[maxn];
int dp[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        rep1(i,n) cin>>a[i]>>b[i];
        int l=1,r=n;
        while (l<r){
            int md=(l+r)>>1;
            auto check=[&](int u){
                int sum=0,cur=0;
                for (int i=1;i<=n;++i){
                    if (b[i]<cur) continue;
                    if (cur+1+a[i]<u) continue;
                    sum++, cur++;
                }  
                return sum>=u;
            };
            if (check(md+1)) l=md+1;
            else r=md; 
        }
        cout<<l<<"\n";
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