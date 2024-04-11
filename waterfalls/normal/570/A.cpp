#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int num[113][113];
int num2[113];

int main() {
    scanf("%d%d",&n,&m);
    swap(n,m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&num[i][j]);
    for (int i=0;i<n;i++) {
        int which = 0;
        for (int j=1;j<m;j++) if (num[i][j]>num[i][which]) which = j;
        num2[which]+=1;
    }
    int which = 0;
    for (int i=1;i<m;i++) if (num2[i]>num2[which]) which = i;
    printf("%d\n",which+1);

    return 0;
}