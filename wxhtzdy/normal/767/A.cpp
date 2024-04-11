#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s;
    int nxt = n;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
        while (true) {
            if (s.size() > 0 && *s.rbegin() == nxt) {
                cout << nxt << " ";
                s.erase(nxt);
                --nxt;
            } else {
                break;
            }
        }
        if (i < n - 1) {
            cout << '\n';
        }
    }
    return 0;
}