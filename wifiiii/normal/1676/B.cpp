#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        cout << accumulate(a.begin(), a.end(), 0) - *min_element(a.begin(), a.end()) * n << '\n';
    }
}