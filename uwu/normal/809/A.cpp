#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

ll arr[MAXN], p2[MAXN], ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    p2[0]=1;
    for (int i=1;i<=n;++i) p2[i]=p2[i-1]*2%mod;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i) ans+=(arr[i]*(p2[i-1]-p2[n-i]+mod))%mod, ans%=mod;
    cout << ans << '\n';
}