#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N = 1e5 + 10;

int n, s;
int a[2][N];
string solve() {
    if (a[0][1] == 0) return "NO";
    if (a[0][s] == 1) return "YES";

    if (a[1][s] == 0) return "NO";
    for(int i = s + 1; i <= n; i++) if (a[0][i] && a[1][i])
        return "YES";
    return "NO";
}
int main() {
    cin >> n >> s;
    for(int i = 0; i <= 1; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    cout << solve();
}