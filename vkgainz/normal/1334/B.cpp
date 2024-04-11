#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> a(n);
        int x; cin >> x;
        long long sum = 0LL;
        for(int i = 0; i < n; i++) {
            cin >> a[i], sum += a[i];
        }
        sort(a.begin(), a.end());
        int b = n;
        for(int i = 0; i < n; i++) {
            if(sum / (n - i) >= x) {
                b = i;
                break; 
            }
            sum -= a[i];
        }
        cout << n - b << "\n";
    }
}