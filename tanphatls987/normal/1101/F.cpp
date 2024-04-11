#include <bits/stdc++.h>

using namespace std;

const int N = 4e2 + 10;
const int inf = 1e9 + 10;

int n;
int a[N];
vector<int> f[N][N];

bool minimize(int &x, int y) {
    if (x > y) x = y; else return 0;
    return 1;
}
int get(int L, int R, int use) {
    use = min(use, R - L);
    return f[L][R][use];
}
void DP(int L, int R, int uL, int uR, int optL, int optR) {
    int uM = (uL + uR) / 2;
    int &ans = f[L][R][uM] = inf; 
    
    int opt = -1;
    for(int i = optL; i <= optR; i++) {
        if (minimize(ans, max(get(L, i, uM - 1), a[R] - a[i])))
            opt = i;
    }
    if (uM > uL) {
        DP(L, R, uL, uM - 1, optL, opt);
    }
    if (uM < uR) {
        DP(L, R, uM + 1, uR, opt, optR);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> n >> test;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int L = n; L >= 1; L--) {
        f[L][L] = vector<int>(1, 0);
        for(int R = L + 1; R <= n; R++) {
            f[L][R] = vector<int>(R - L + 1, 0);
            f[L][R][0] = a[R] - a[L];
            DP(L, R, 1, R - L, L, R - 1); 
        }
    }
    long long ans = 0;
    while (test--) {
        int L, R, cost, use;
        cin >> L >> R >> cost >> use;
        //cout << get(L, R, use) << endl;
        ans = max(ans, 1LL * get(L, R, use) * cost);
    }
    cout << ans;
}