#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> arr(n+1);
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    ll ans=0;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            for (int j=1;j<=n;++j){
                ans=max(ans,arr[i]|arr[k]|arr[j]);
            }
        }
    }
    cout << ans << '\n';
}