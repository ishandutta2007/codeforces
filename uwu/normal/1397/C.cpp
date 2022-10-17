#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

ll arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    if (n==1){
        cout << 1 << " " << 1 << '\n';
        cout << -arr[1] << '\n';
        cout << 1 << " " << 1 << '\n' << 0 << '\n';
        cout << 1 << " " << 1 << '\n' << 0 << '\n';
        return 0;
    }
    cout << 1 << " " << n-1 << '\n';
    for (int i=1;i<n;++i){
        cout << (n-1)*((ll)(arr[i]+(n*1e9))%n) << '\n';
        arr[i]+=(n-1)*((ll)(arr[i]+(n*1e9))%n);
    }
    cout << n << " " << n << '\n';
    cout << -arr[n] << '\n'; arr[n]=0;
    cout << 1 << " " << n << '\n';
    for (int i=1;i<=n;++i) cout << -arr[i] << " ";
}