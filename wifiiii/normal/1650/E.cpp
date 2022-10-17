#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        n += 1;
        vector<int> a(n);
        for(int i = 1; i < n; ++i) cin >> a[i];
        int lo = 0, hi = 1e9;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int f = 0;
            if(d - a[n - 1] - 1 >= mid) f = 1;
            for(int i = 0; i + 1 < n; ++i) {
                if(a[i + 1] - a[i] - 1 >= mid * 2 + 1) f = 1;
            }
            auto check = [&]() {
                for(int i = 0; i + 1 < n; ++i) {
                    if(a[i + 1] - a[i] - 1 < mid) {
                        if(i + 2 < n && a[i + 2] - a[i] - 1 < mid) return 0;
                        for(int j = i + 2; j + 1 < n; ++j) {
                            if(a[j + 1] - a[j] - 1 < mid) return 0;
                        }
                        if(i + 2 < n && a[i + 2] - a[i + 1] - 1 < mid) {
                            // move i + 1
                            return f;
                        } else {
                            if(f) return 1;
                            // move i or i + 1
                            if(i != 0 && a[i + 1] - (a[i - 1] + mid + 1) - 1 >= mid) return 1;
                            if(i + 2 == n && d - a[i] - 1 >= mid) return 1;
                            if(i + 2 != n && a[i + 2] - mid - a[i] - 2 >= mid) return 1;
                            return 0;
                        }
                    }
                }
                return 1;
            };
            if(check()) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << '\n';
    }
}