#include<bits/stdc++.h>
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
        int sum = accumulate(a.begin(), a.end(), 0);
        if(sum % n) {
            cout << -1 << '\n';
            continue;
        }
        int aver = sum / n;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] > aver) cnt += 1;
        }
        cout << cnt << '\n';
    }
}