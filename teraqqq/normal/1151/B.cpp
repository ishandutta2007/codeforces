#include <bits/stdc++.h>

using namespace std;

const int N = 507;

int n, m, a[N][N], x, q[N], r[N];
bool ok = true;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if(a[i][j] != a[i][0]) q[i] = j;
        }
        x = x ^ a[i][0];
    }
    
    ok = x != 0;
    for(int i = 0; !ok && i < n; ++i) 
        if(q[i]) r[i] = q[i], ok = true;
    if(ok) {
        cout << "TAK" << endl;
        for(int i = 0; i < n; ++i) cout << r[i]+1 << ' ';
        cout << endl;
    }
    else cout << "NIE" << endl;
}