#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        ll curr=1;
        ll ans=0;
        for (ll i=0;curr<=n;++i,curr+=2){
            ans+=(4*curr-4)*i;
        }
        cout << ans << '\n';
    }
}