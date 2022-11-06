#include <bits/stdc++.h>
using namespace std;

int id1[1000], id2[1000];

int main() {
    id1['v'] = 0; id1['<'] = 1; id1['^'] = 2; id1['>'] = 3;
    id2['v'] = 0; id2['>'] = 1; id2['^'] = 2; id2['<'] = 3;
    char a, b; cin >> a >> b;
    int n; cin >> n;
    int d = ((id1[b] - id1[a]) + 4) % 4;
    int e = ((id2[b] - id2[a]) + 4) % 4;
    if (n % 4 == d && n % 4 != e) cout << "cw" << endl;
    else if (n % 4 == e && n % 4 != d) cout << "ccw" << endl;
    else cout << "undefined" << endl;
    return 0;
}