#include <cstdio>
#include <algorithm>

using namespace std;

int need[113][113];
int has[113][113];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        char c;
        scanf(" %c",&c);
        if (c=='W') need[i][j] = 1;
        else need[i][j] = -1;
    }
    int ans = 0;
    for (int i=n-1;i>=0;i--) for (int j=m-1;j>=0;j--) {
        if (has[i][j]!=need[i][j]) {
            int diff = need[i][j]-has[i][j];
            ans+=1;
            for (int a=0;a<=i;a++) for (int b=0;b<=j;b++) has[a][b]+=diff;
        }
    }
    printf("%d\n",ans);

    return 0;
}