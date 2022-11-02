#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 5000 + 10;
const int MM = 1e9 + 7;

char s[MAXN], ss[MAXN];
int n, k, nn;
int t[MAXN];
vector<int> f[MAXN][32];
int vis[MAXN * 4];

void solve(int casi){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        t[i] = s[i] - 'a';
    }
    k = 0;
    for (int j = 1; j * 2 <= n; j *= 2) {
        k++;
    }
    nn = (1 << k) - 1;
    f[0][0].push_back(0);
    int len = n - nn + 1;
    for (int i = 0; i <= len; i++) {
        int ch = 0;
        while (f[i][ch].empty()) {
            ch++;
        }
        ss[i] = ch + 'a';
        // i ~ n
        for (int j = i; j <= n; j++) vis[j] = 0;
        for (auto &j : f[i][ch]) vis[j] = 1;
        for (int j = i; j <= n; j++) if (vis[j]) {
            int msk = j - i;
            for (int l = 0; l < k; l++) {
                if (!((msk >> l) & 1)) {
                    vis[j + (1 << l)] = 1;
                }
            }
        }
        for (int j = i; j <= n; j++) {
            if (vis[j]) {
                f[i + 1][t[j]].push_back(j + 1);
            }
        }
    }
    // for (int i = 0; i <= len; i++) {
    //     cout << ss[i] << ' ';
    // } cout << endl;
    ss[len + 1] = 0;
    printf("%s\n", ss + 2);
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}