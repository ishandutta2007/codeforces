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
const int mod=1e9+7;
int n,a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    int sum=0;
    while (_--){
        cin>>n;
        int ans=1;
        rep1(i,n) cin>>a[i];
        for (int i=1;i<n;++i){
            int cur=n,sum=0;
            while (cur>=i){
                if (a[cur]==a[i]) {sum+=(cur-i+1); break;}
                int to=upper_bound(a+1,a+1+n,(a[cur]+a[i])/2)-a-1;
                sum++, cur=to;
            }
            ans=max(ans,sum);
        }
        cout<<n-ans<<"\n";
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