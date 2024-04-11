#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, q; cin >> n >> q;
        for (int i=1;i<=n;++i) cin >> arr[i];
        int p=n, idx;
        for (;p>0;--p) if (arr[p]!=p) break;
        double ans=1, pi;
        while (q--){
            cin >> idx >> pi;
            if (idx>=p) ans*=(1-pi);
        }
        if (p==0){ cout << 1 << '\n'; continue; }
        cout << fixed << setprecision(9) << 1-ans << '\n';
    }
}