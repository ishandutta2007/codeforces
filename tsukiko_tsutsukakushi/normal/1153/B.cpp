#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define FOR(i, s, e) for (int (i) = (s); (i) < (e); (i)++)

int main() {
    int n, m ,h; cin >> n >> m >> h;
    int a[110], b[110], c[110][110];
    FOR(i,0, m) cin >> a[i];
    FOR(i,0,n) cin >> b[i];
    FOR(i,0,n) {
        FOR(j,0,m) cin >> c[i][j];
    }

    int ans[110][110] ={0};
    FOR(i,0,n) {
        FOR(j,0,m) {
            if (c[i][j] != 0) ans[i][j] = min(b[i],a[j]);
        }
    }

    FOR(i,0,n) {
        FOR(j,0,m - 1) {
            
            cout << ans[i][j] << " ";
        }
        cout << ans[i][m-1] << endl;
    }
}