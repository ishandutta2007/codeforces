#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s; cin >> s;
    s += '0';
    pair<int, int> sto = {n + 1, 0};
    pair<int, int> curr = {n + 1, 0};
    for(int i = 0; i < n; i++) {
        curr.first = min(curr.first, a[i]);
        curr.second = max(curr.second, a[i]);
        if(s[i] == '0') {
            if(curr.first < sto.second) {
                cout << "NO" << "\n";
                return 0;
            }
            sto = curr;
            curr = {n + 1, 0};
        }
    }
    cout << "YES";
}