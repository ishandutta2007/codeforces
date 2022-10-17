#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int x = count(s.begin(), s.end(), '0'), y = count(s.begin(), s.end(), '1');
        cout << (x == y ? x - 1 : min(x, y)) << '\n';
    }
}