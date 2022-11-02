#include <cstdio>
#include <algorithm>

using namespace std;

int n;
bool pos[113][113];
#define next next_
bool next[113][113];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
        char c;
        scanf(" %c",&c);
        pos[i][j] = c-'0';
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (pos[i][j]) {
                for (int k=0;k<n;k++) next[k][j] = pos[k][j];
            } else {
                for (int k=0;k<n;k++) next[k][j] = !pos[k][j];
            }
        }
        int cur = 0;
        for (int j=0;j<n;j++) {
            int ok = 1;
            for (int k=0;k<n;k++) if (!next[j][k]) ok = 0;
            if (ok) cur+=1;
        }
        ans = max(ans,cur);
    }
    printf("%d\n",ans);

    return 0;
}