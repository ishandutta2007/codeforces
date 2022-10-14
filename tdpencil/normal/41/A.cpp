#include <bits/stdc++.h>

using ll = long long;

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());

    wcout << (a == b ? "YES\n": "NO\n");; 
}