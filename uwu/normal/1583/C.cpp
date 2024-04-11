#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<char>> a = vector<vector<char>>(N + 1, vector<char>(M + 1));
    vector<int> bad = vector<int>(M + 1);
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> a[i][j];
            if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X'){
                bad[j] = 1;
            }
        }
    }
    for (int i = 1; i <= M; ++i) bad[i] += bad[i - 1];
    int Q; cin >> Q;
    for (int i = 1; i <= Q; ++i){
        int l, r; cin >> l >> r;
        cout << (bad[r] - bad[l] == 0 ? "YES" : "NO") << '\n';
    }
}