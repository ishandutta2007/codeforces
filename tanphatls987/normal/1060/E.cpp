#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 2e5 + 10;
int n;
int q[N], pa[N];
vector <int> v[N];

int sub[N][2];
long long d[N][2];

long long solve() { 
    int top = 1, bot = 1;
    q[1] = 1;
    while (top <= bot){
        int x = q[top++];
        for(auto y : v[x]) if (y != pa[x]){
            pa[y] = x;
            q[++bot] = y;
        }
    }
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        int x = q[i];
        sub[x][0] = 1;
        for(auto y : v[x]) if (y != pa[x]){
            for(int i = 0; i <= 1; i++)
                for(int j = 0; j <= 1; j++) {
                    int com = i ^ j ^ 1;
                    long long dist = 1LL * sub[x][i] * sub[y][j] + 1LL * d[x][i] * sub[y][j] + 1LL * d[y][j] * sub[x][i];
                    if (com & 1) dist += 1LL * sub[x][i] * sub[y][j];
                    ans += dist / 2;
                }
            for(int i = 0; i <= 1; i++){
                d[x][i] += d[y][i ^ 1] + sub[y][i ^ 1];
                sub[x][i] += sub[y][i ^ 1];
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << solve();
}