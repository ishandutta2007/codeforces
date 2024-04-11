#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;

void solve() {
    int n; cin >> n;
    int a[n];
    ll sum = 0;
    ll x = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum+=a[i];
        x^=a[i];
    }
    cout << 2 << endl;
    cout << x << " " << x+sum << "\n";
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}