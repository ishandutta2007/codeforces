#include <cstdio>

using namespace std;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    char table[n][m+1];
    for (int i=0;i<n;i++) scanf(" %s",&table[i]);
    int done[n][n];
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) done[i][j] = 0;
    int gone[m];
    for (int i=0;i<m;i++) gone[i] = 0;
    for (int k=0;k<m;k++) {
        for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (table[i][k]>table[j][k] && !done[i][j]) gone[k] = 1;
        for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (table[j][k]>table[i][k] && !gone[k]) done[i][j] = 1;
    }
    int ans = 0;
    for (int i=0;i<m;i++) ans+=gone[i];
    printf("%d\n",ans);

    return 0;
}