#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int cnt = 0, p = -1;
        for(int i = 0; i < n; ++i) {
            if(a[i] == 1) {
                p = i;
                cnt += 1;
            }
        }
        if(cnt != 1) {
            cout << "No\n";
            continue;
        }
        rotate(a.begin(), a.begin() + p, a.end());
        int yes = 1;
        for(int i = 1; i < n; ++i) {
            if(a[i] > a[i - 1] + 1) {
                yes = 0;
                break;
            }
        }
        cout << (yes ? "Yes" : "No") << '\n';
    }
}