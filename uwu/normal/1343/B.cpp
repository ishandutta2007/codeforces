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
        int n; cin >> n;
        if (n%4==2){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        ll ans=0;
        for (int i=1;i<=n/2;++i){
            cout << 2*i << " ";
            ans+=2*i;
        }
        for (int i=1;i<n/2;++i){
            cout << 2*i-1 << " ";
            ans-=2*i-1;
        }
        cout << ans << '\n';

    }
}