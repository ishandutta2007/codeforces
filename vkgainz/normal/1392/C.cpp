#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n; cin >> n;
    int a[n]; for(int i=0;i<n;i++) cin >> a[i];
    ll ans = 0;
    for(int i=0;i<n-1;i++)
        ans+=max(a[i]-a[i+1],0);
    cout << ans << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}