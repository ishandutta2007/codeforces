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
        string s;
        cin >> s;
        if(count(s.begin(), s.end(), '1') > 1 || count(s.begin(), s.end(), '0') > 1) cout << "NO\n";
        else cout << "YES\n";
    }
}