#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

pii solve(ll a){
    ll l=10,r=-1;
    while (a!=0){
        l=min(l,a%10);
        r=max(r,a%10);
        a=a/10;
    }
    return {l,r};
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    pii uwu;
    while (t--){
        ll n,k; cin >> n >> k;
        for (int i=1;i<k;++i){
            uwu=solve(n);
            if (uwu.f==0) break;
            n=n+uwu.f*uwu.s;
        }
        cout << n << '\n';
    }
}