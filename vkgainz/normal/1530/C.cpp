#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        int lo = 0, hi = 10000000;
        for(int j = 0; j < 30; j++) {
            int mid = (lo + hi) / 2;
            int stage = n + mid - (n + mid) / 4;
            int score_a = 0, score_b = 0;
            if(mid >= stage) {
                score_a = stage * 100;
            }
            else {
                score_a = mid * 100;
                for(int i = 0; i < stage - mid; i++) {
                    score_a += a[i];
                }
            }
            for(int i = 0; i < min(n, stage); i++) {
                score_b += b[i];
            }
            if(score_a >= score_b) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
        
    }
}