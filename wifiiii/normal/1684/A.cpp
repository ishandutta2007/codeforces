#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.size() == 2) {
            cout << s.back() << '\n';
        } else {
            cout << *min_element(s.begin(), s.end()) << '\n';
        }
    }
}