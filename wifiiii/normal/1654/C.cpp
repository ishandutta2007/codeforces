#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        multiset<ll> s;
        int n;
        cin >> n;
        ll sum = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x;
            s.insert(x);
        }
        priority_queue<ll, vector<ll>, greater<ll>> a;
        a.push(sum);
        int ok = 1;
        while(!s.empty()) {
            ll x = a.top(); a.pop();
            if(s.count(x)) {
                s.erase(s.find(x));
                continue;
            }
            if(x < *s.begin()) {
                ok = 0;
                break;
            }
            ll l = x / 2, r = x - l;
            a.push(l);
            a.push(r);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}