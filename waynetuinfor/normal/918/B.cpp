#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000;
map<string, string> ip;

int main() {
    int n, m; cin >> n >> m;
    while (n--) {
        string a, b; cin >> a >> b;
        ip[b] = a;
    }
    while (m--) {
        string a, b; cin >> a >> b;
        b = b.substr(0, b.size() - 1);
        cout << a << ' ' << b << ';' << " #" << ip[b] << endl;
    }
    return 0;
}