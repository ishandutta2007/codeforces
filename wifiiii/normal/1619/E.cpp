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
        vector<int> a(n + 1);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }
        ll ok = 1, s = 0, c = 0;
        priority_queue<int> q;
        for(int i = 0; i <= n; ++i) {
            if(!ok) {
                cout << -1 << " ";
                continue;
            }
            s += a[i];
            cout << c + a[i] << " ";
            if(a[i]) {
                --a[i];
                while(a[i]) q.push(i), --a[i];
            } else {
                if(q.empty()) {
                    ok = 0;
                } else {
                    c += i - q.top(); q.pop();
                }
            }
        }
        cout << '\n';
    }
}