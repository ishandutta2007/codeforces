#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        vector<int> del(26);
        reverse(a.begin(), a.end());
        for(char c : a) {
            if(del[c - 'A']) continue;
            if(del[b.back() - 'A']) break;
            if(c != b.back()) {
                del[c - 'A'] = 1;
            } else {
                b.pop_back();
            }
            if(b.empty()) break;
        }
        if(b.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}