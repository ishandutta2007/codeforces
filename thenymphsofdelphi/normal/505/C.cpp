#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int M = 30001;
 
int dp[M][250*2];
bool used[M][250*2] = {};
 
int d;
int gem[M] = {};
 
int solve(int i, int j) {
    int jj = j-(d-250);
    if (i >= M) return 0;
    if (used[i][jj]) return dp[i][jj];
    used[i][jj] = true;
    int res;
    if (j == 1) {
        res = gem[i] + max(solve(i+j, j), solve(i+j+1, j+1));
    } else {
        res = gem[i] + max(max(solve(i+j-1, j-1), solve(i+j, j)), solve(i+j+1, j+1));
    }
    dp[i][jj] = res;
    return res;
}
 
int main() {
    int n;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        gem[x]++;
    }
    printf("%d\n", solve(d, d));
    return 0;
}