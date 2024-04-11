#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, Q; cin >> N >> Q;
        vector<vector<ll>> a(1001, vector<ll>(1001));
        for (int i = 1; i <= N; ++i){
            int x, y; cin >> x >> y;
            a[x][y] += x*y;
        }
        for (int i = 1; i <= 1000; ++i){
            for (int j = 1; j <= 1000; ++j){
                a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            }
        }
        while (Q--){
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            x2--, y2--;
            x1++, y1++;
            cout << a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1] << '\n';
        }
    }
}