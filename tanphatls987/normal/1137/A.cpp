#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int pos[2][N][N];
int n, m;

int a[N][N];
int re[2][N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    for(int i = 1; i <= n; i++) {
        vector<int> p;
        for(int j = 1; j <= m; j++) {
           p.push_back(a[i][j]); 
        }
        sort(p.begin(), p.end());

        re[0][i] = unique(p.begin(), p.end()) - p.begin();


        for(int j = 1; j <= m; j++)
            pos[0][i][j] = lower_bound(p.begin(), p.begin() + re[0][i], a[i][j]) - p.begin();
    }
    for(int j = 1; j <= m; j++) {
        vector<int> p;
        for(int i = 1; i <= n; i++) {
           p.push_back(a[i][j]); 
        }
        sort(p.begin(), p.end());

        re[1][j] = unique(p.begin(), p.end()) - p.begin();


        for(int i = 1;i <= n; i++)
            pos[1][i][j] = lower_bound(p.begin(), p.begin() + re[1][j], a[i][j]) - p.begin();
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int pre = max(pos[0][i][j], pos[1][i][j]);
            int suf = max(re[0][i] - pos[0][i][j], re[1][j] - pos[1][i][j]);
            cout << pre + suf << " \n"[j == m];
        }
    }
}