#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            cout << "? " << lo << ' ' << mid << endl;
            int m = mid - lo + 1;
            vector<int> a(m);
            for(int i = 0; i < m; ++i) cin >> a[i];
            int cnt = 0;
            for(int x : a) {
                if(lo <= x && x <= mid) ++cnt;
            }
            if(cnt & 1) hi = mid;
            else lo = mid + 1;
        }
        cout << "! " << lo << endl;
    }
}