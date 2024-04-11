#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        if(s.substr(0, n / 2) + s.substr(0, n / 2) == s) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}