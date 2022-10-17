#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int dir1[8] = {-1,-1,-1,0,0,1,1,1};
int dir2[8] = {-1,0,1,-1,1,-1,0,1};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> sa(n + 1, vector<int>(m + 1));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            sa[i + 1][j + 1] = a[i][j] == 'X';
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            sa[i][j] += sa[i-1][j];
        }
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            sa[i][j] += sa[i][j-1];
        }
    }
    int lo = 0, hi = min(n, m);
    while(lo < hi) {
        int mid2 = (lo + hi + 1) / 2, mid = 2 * mid2 + 1;
        vector<vector<int>> b(n, vector<int>(m));
        for(int i = 0; i + mid <= n; ++i) {
            for(int j = 0; j + mid <= m; ++j) {
                if(sa[i + mid][j + mid] + sa[i][j] - sa[i + mid][j] - sa[i][j + mid] == mid * mid) {
                    b[i][j] += 1;
                    if(i + mid < n) b[i + mid][j] -= 1;
                    if(j + mid < m) b[i][j + mid] -= 1;
                    if(i + mid < n && j + mid < m) b[i + mid][j + mid] += 1;
                }
            }
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                b[i][j] += b[i-1][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                b[i][j] += b[i][j-1];
            }
        }
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if((b[i][j] > 0) ^ (a[i][j] == 'X')) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) lo = mid2;
        else hi = mid2 - 1;
    }
    cout << lo << '\n';
    int mid = lo * 2 + 1;
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    for(int i = 0; i + mid <= n; ++i) {
        for(int j = 0; j + mid <= m; ++j) {
            if(sa[i + mid][j + mid] + sa[i][j] - sa[i + mid][j] - sa[i][j + mid] == mid * mid) {
                ans[i + lo][j + lo] = 'X';
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}