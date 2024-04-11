#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) a[i] -= i;
    multiset<int> s;
    ll ans = 0;
    for(int x : a) {
        s.insert(x);
        if(*--s.end() > x) {
            ans += *--s.end() - x;
            s.erase(--s.end());
            s.insert(x);
        }
    }
    cout << ans << '\n';
}