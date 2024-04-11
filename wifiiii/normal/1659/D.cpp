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
        vector<int> c(n + 1);
        for(int i = 1; i <= n; ++i) cin >> c[i];
        vector<int> a(n + 1, 1);
        for(int i = 1; i <= n; ++i) {
            if(c[i] == 0) {
                a[i] = 0;
            } else {
                break;
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(a[i] == 0) {
                if(c[i] + i <= n) a[c[i] + i] = 0;
            } else {
                if(c[i] + 1 <= n) a[c[i] + 1] = 0;
            }
        }
        for(int i = 1; i <= n; ++i) cout << a[i] << " "; cout << '\n';
    }
}