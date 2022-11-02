#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
bool grid[2000][2000];
bool u[2000][2000];
bool d[2000][2000];
bool l[2000][2000];
bool r[2000][2000];
int dl[2000][2000];
int udr[2000][2000];
int dr[2000][2000];
int ru[2000][2000];
int lrd[2000][2000];
int rd[2000][2000];

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        char c;
        scanf(" %c",&c);
        if (c=='#') grid[i][j] = 1;
    }
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        if (grid[i][j]) continue;
        if (i==0 || u[i-1][j]) u[i][j] = 1;
        if (j==0 || l[i][j-1]) l[i][j] = 1;
    }
    for (int i=n-1;i>=0;i--) for (int j=m-1;j>=0;j--) {
        if (grid[i][j]) continue;
        if (i==n-1 || d[i+1][j]) d[i][j] = 1;
        if (j==m-1 || r[i][j+1]) r[i][j] = 1;
    }
    long long ans = 0;
    // 0 turns
    // - horizontal
    for (int i=1;i<n-1;i++) ans+=l[i][m-1];
    // - vertical
    for (int j=1;j<m-1;j++) ans+=u[n-1][j];
    // 1 turn
    for (int i=1;i<n-1;i++) for (int j=1;j<m-1;j++) {
        ans+=u[i][j]&l[i][j];
        ans+=u[i][j]&r[i][j];
        ans+=d[i][j]&l[i][j];
        ans+=d[i][j]&r[i][j];
    }
    // 2 turns
    // - some nice sums
    for (int i=1;i<n-1;i++) for (int j=1;j<m-1;j++) if (!grid[i][j]) dl[i][j] = dl[i][j-1]+d[i][j];
    for (int i=1;i<n-1;i++) for (int j=m-2;j>0;j--) if (!grid[i][j]) udr[i][j] = udr[i][j+1]+u[i][j]+d[i][j];
    for (int i=1;i<n-1;i++) for (int j=m-2;j>0;j--) if (!grid[i][j]) dr[i][j] = dr[i][j+1]+d[i][j];
    for (int i=1;i<n-1;i++) for (int j=1;j<m-1;j++) if (!grid[i][j]) ru[i][j] = ru[i-1][j]+r[i][j];
    for (int i=n-2;i>0;i--) for (int j=1;j<m-1;j++) if (!grid[i][j]) lrd[i][j] = lrd[i+1][j]+l[i][j]+r[i][j];
    for (int i=n-2;i>0;i--) for (int j=1;j<m-1;j++) if (!grid[i][j]) rd[i][j] = rd[i+1][j]+r[i][j];
    // - vertical (except bottom U)
    for (int i=1;i<n-1;i++) for (int j=1;j<m-1;j++) {
        if (!u[i][j]) continue;
        ans+=dl[i][j-1];
        if (j!=m-2 && !grid[i][j+1]) ans+=udr[i][j+2];
        if (j!=m-2) ans+=d[i][j+1];
    }
    // bottom U
    for (int i=1;i<n-1;i++) for (int j=1;j<m-2;j++) {
        if (!d[i][j]) continue;
        if (!grid[i][j+1]) ans+=dr[i][j+2];
    }
    // - horizontal (except right U)
    for (int j=1;j<m-1;j++) for (int i=1;i<n-1;i++) {
        if (!l[i][j]) continue;
        ans+=ru[i-1][j];
        if (i!=n-1 && !grid[i+1][j]) ans+=lrd[i+2][j];
        if (i!=n-2) ans+=r[i+1][j];
    }
    // right U
    for (int j=1;j<m-1;j++) for (int i=1;i<n-2;i++) {
        if (!r[i][j]) continue;
        if (!grid[i+1][j]) ans+=rd[i+2][j];
    }
    printf("%I64d\n",ans);

    return 0;
}