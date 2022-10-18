#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mnx = n, mny = m, mxx = -1, mxy = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == 'B'){
                mnx = min(mnx, i);
                mxx = max(mxx, i);
                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
    }
    cout << (mnx + mxx) / 2 + 1 << ' ' << (mny + mxy) / 2 + 1;
}