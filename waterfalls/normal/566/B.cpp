#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[120013];
int b[120013];
int c[120013];
bool done[120013];
int num[30013];
vector<int> rules;

void upd(int i, int d) {
    num[a[i]]-=d;
    num[b[i]]+=d;
    num[c[i]]+=d;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) num[i] = 4;
    for (int i=1;i<=4*n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    while (rules.size()<4*n) {
        for (int j=1;j<=4*n;j++) {
            if (done[j]) continue;
            upd(j,1);
            if (num[b[j]]<=9 && num[c[j]]<=9) rules.push_back(j), done[j] = 1;
            else upd(j,-1);
        }
    }
    printf("YES\n");
    for (int i: rules) printf("%d ",i);
    printf("\n");

    return 0;
}