#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int arr[MAXN];

void solve(){
    ll n, u, v; cin >> n >> u >> v;
    for (int i=1;i<=n;++i) cin >> arr[i];
    int tmp=0;
    for (int i=2;i<=n;++i){
        tmp=max(tmp,abs(arr[i]-arr[i-1]));
    }
    if (tmp==0) cout << min(2*v,v+u) << '\n';
    else if (tmp==1) cout << min(u,v) << '\n';
    else cout << 0 << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
}