#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(k == 0) {
            cout << 1 << '\n';
        } else {
            cout << (s == string(s.rbegin(), s.rend()) ? 1 : 2) << '\n';
        }
    }
}