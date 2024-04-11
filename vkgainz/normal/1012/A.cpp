#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
    int n; cin >> n;
    int a[2*n];
    for(int i=0;i<2*n;i++) cin >> a[i];
    sort(a, a+2*n);
    ll ans = (a[n-1]-a[0])*1LL*(a[2*n-1]-a[n]);
    ll mn = 1000000000;
    for(int i=1;i<n;i++) {
        mn = min(mn, (ll)a[i+n-1]-a[i]);
    }
    ans = min(ans, (a[2*n-1]-a[0])*1LL*mn);
    cout << ans << endl;
}