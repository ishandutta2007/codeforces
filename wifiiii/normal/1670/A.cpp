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
        int cnt = 0;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] < 0) ++cnt;
            a[i] = abs(a[i]);
        }
        for(int i = 0; i < cnt; ++i) a[i] = -a[i];
        if(is_sorted(a.begin(), a.end())) cout << "YES\n";
        else cout << "NO\n";
    }
}