#include <cstdio>
#include <algorithm>

using namespace std;

#define prev prev_
#define next next_

int n,m;
char grid[513][513];
int prev[513][513];
int next[513][513];

const int MOD = 1000000007;

inline bool outn(int x) { return x<0 || x>=n; }
inline bool outm(int x) { return x<0 || x>=m; }

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
    if (grid[0][0]!=grid[n-1][m-1]) return printf("0\n"), 0;
    prev[0][n-1] = 1;
    for (int r=1;r<(m+n)/2;r++) {
        for (int i=0;i<max(m,n);i++) for (int j=0;j<max(m,n);j++) {
            next[i][j] = 0;
            if (outn(i) || outm(r-i)) continue;
            if (outn(j) || outm(m+n-2-r-j)) continue;
            if (grid[i][r-i]!=grid[j][m+n-2-r-j]) continue;
            if (i && j<n-1) next[i][j] = (next[i][j]+prev[i-1][j+1])%MOD;
            if (i) next[i][j] = (next[i][j]+prev[i-1][j])%MOD;
            if (j<n-1) next[i][j] = (next[i][j]+prev[i][j+1])%MOD;
            next[i][j] = (next[i][j]+prev[i][j])%MOD;
        }
        swap(prev,next);
    }
    int ans = 0;
    if ((m+n)%2==0) {
        for (int i=0;i<max(m,n);i++) ans = (ans+prev[i][i])%MOD;
    } else {
        for (int i=0;i<max(m,n);i++) {
            ans = (ans+prev[i][i])%MOD;
            if (i) ans = (ans+prev[i-1][i])%MOD;
        }
    }
    printf("%d\n",ans);

    return 0;
}