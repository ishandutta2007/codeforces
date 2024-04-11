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
int n;
int a[maxn],f[maxn],rf[maxn];
int cnt[maxn];
int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n;
    rep(i,n) {
        cin>>a[i];
        int k=0;
        while (a[i]%2==0) a[i]/=2, k++;
        cnt[k]++;
    }
    int ans=0;
    for (int i=1;i<=33;++i){
        if (!cnt[i]) continue;
        int sum=0,tmp=0;
        for (int j=i;j<=33;++j){
            sum+=cnt[j];
        }
        ans=(ans+modpow(2,sum-1))%mod;
    }
    cout<<(modpow(2,n)-ans-1+2*mod)%mod;
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