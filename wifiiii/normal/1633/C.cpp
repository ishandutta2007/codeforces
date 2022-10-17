#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        auto check = [&](ll hc, ll dc, ll hm, ll dm) {
            return (hm + dc - 1) / dc <= (hc + dm - 1) / dm;
        };
        ll hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        int win = 0;
        for(int i = 0; i <= k; ++i) {
            if(check(hc + i * a, dc + (k - i) * w, hm, dm)) {
                win = 1;
                break;
            }
        }
        cout << (win ? "YES" : "NO") << '\n';
    }
}