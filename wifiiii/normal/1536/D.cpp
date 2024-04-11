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
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ok = 1;
        set<int> s;
        s.insert(a[0]);
        for(int i = 1; i < a.size(); ++i) {
            auto it = s.lower_bound(a[i]);
            int f = 0;
            if(it != s.end() && *it == a[i-1]) f = 1;
            if(it != s.begin() && *(--it) == a[i-1]) f = 1;
            it = s.lower_bound(a[i]);
            if(it != s.end() && *it == a[i] && ++it != s.end() && *it == a[i-1]) f = 1;
            if(f == 0) {
                ok = 0;
                break;
            }
            s.insert(a[i]);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}