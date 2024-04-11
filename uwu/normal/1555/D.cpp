#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 2e5+1;

int n, m;
string s;
int psa[MAXN][6];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s; s = " " + s;
    vector<char> per = {'a', 'b', 'c'};
    int idx = 0;
    do{
        for (int i = 1; i <= n; ++i){
            if (s[i] != per[i % 3]) psa[i][idx]++;
            if (i) psa[i][idx] += psa[i - 1][idx];
        }
        idx++;
    } while(next_permutation(per.begin(), per.end()));
    while (m--){
        int l, r; cin >> l >> r;
        int ans = inf;
        for (int i = 0; i < 6; ++i){
            ans = min(ans, psa[r][i] - psa[l - 1][i]);
        }
        cout << ans << '\n';
    }
}