#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> a(s.size() + 1);
    for(int i = 1; i <= s.size(); ++i) a[i] = a[i-1] + s[i-1] - 'a' + 1;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
}