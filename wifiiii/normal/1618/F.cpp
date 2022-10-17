#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll x, y;
    cin >> x >> y;
    string a, b;
    cin >> a >> b;
    while(x) {
        a += char(x % 2 + '0');
        x /= 2;
    }
    while(y) {
        b += char(y % 2 + '0');
        y /= 2;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    auto chk = [](string a, string b) -> int {
        if(a == b) return 1;
        if(a.size() > b.size()) return 0;
        for(int i = 0; i <= b.size() - a.size(); ++i) {
            string newa = string(i, '1') + a + string(b.size() - a.size() - i, '1');
            if(newa == b) return 1;
        }
        reverse(a.begin(), a.end());
        for(int i = 0; i <= b.size() - a.size(); ++i) {
            string newa = string(i, '1') + a + string(b.size() - a.size() - i, '1');
            if(newa == b) return 1;
        }
        return 0;
    };
    string c = a + '1';
    if(chk(c, b) || a == b) {
        cout << "YES\n";
    } else {
        while(a.back() == '0') a.pop_back();
        if(chk(a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}