#include <bits/stdc++.h>
using namespace std;

const int N = 1231231;

int n, m, x, y;
long long Sx[N], Sy[N], ans;

vector <int> cx[N], cy[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            scanf("%d", &x);
            cx[x].push_back(i);
            cy[x].push_back(j);
        }
    }
    const int MAX = 1e5;
    for(int i = 1; i <= MAX; ++ i) {
        sort(cx[i].begin(), cx[i].end());
        sort(cy[i].begin(), cy[i].end());
        for(int j = 0; j < (int) cx[i].size(); ++ j) {
            ans += (cx[i][j] + cy[i][j]) * 1LL * ((int)cx[i].size() - 2 * j - 1);
        }
    }
    cout << -ans << endl;
}