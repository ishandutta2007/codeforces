#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 60;

int n;
int psum[N][N];
int a[N][N];
int f[N][N][N][N];

int getRect(int xa, int ya, int xb, int yb) {
    return psum[xb][yb] - psum[xb][ya - 1] - psum[xa - 1][yb] 
        + psum[xa - 1][ya - 1];
}
int DP(int xa, int ya, int xb, int yb) {
    int &ans = f[xa][ya][xb][yb];
    if (ans != -1) return ans;

    if (getRect(xa, ya, xb, yb) == 0) 
        return ans = 0;
    ans = max(xb - xa + 1, yb - ya + 1);


    for(int dx = xa; dx < xb; dx++)
        ans = min(ans, DP(xa, ya, dx, yb) + DP(dx + 1, ya, xb, yb)); 
    for(int dy = ya; dy < yb; dy++)
        ans = min(ans, DP(xa, ya, xb, dy) + DP(xa, dy + 1, xb, yb)); 
    return ans;


}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++) 
            a[i][j] = s[j - 1] == '#';
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
    memset(f, -1, sizeof(f));
    cout << DP(1, 1, n, n);
}