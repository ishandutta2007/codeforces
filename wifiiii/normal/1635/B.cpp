#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cnt = 0;
        for(int i = 1; i + 1 < n; ++i) {
            if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
                cnt += 1;
                if(i + 2 < n && a[i + 2] >= a[i]) a[i + 1] = a[i + 2];
                else a[i + 1] = a[i];
            }
        }
        cout << cnt << '\n';
        for(int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}