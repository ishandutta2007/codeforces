#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        int p = ceil(sqrt(k) - 1e-10);
        int r = min(p, k - (p - 1) * (p - 1));
        int c = p - max(0, k - (p - 1) * (p - 1) - p);
        cout << r << " " << c << endl;
    }
}