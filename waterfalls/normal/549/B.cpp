#include <cstdio>
#include <algorithm>

using namespace std;

int con[113][113];
int bad[113];
int cur[113];
int take[113];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
        char c;
        scanf(" %c",&c);
        if (c=='1') con[i][j] = 1;
    }
    for (int i=0;i<n;i++) scanf("%d",&bad[i]);
    int m = 0;
    for (int r=0;r<n;r++) {
        for (int i=0;i<n;i++) if (cur[i]==bad[i]) {
            for (int j=0;j<n;j++) if (con[i][j]) cur[j]+=1;
            m+=1;
            take[i] = 1;
        }
    }
    printf("%d\n",m);
    for (int i=0;i<n;i++) if (take[i]) printf("%d ",i+1);
    printf("\n");

    return 0;
}