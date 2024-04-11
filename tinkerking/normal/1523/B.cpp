#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
LL a[5010];

void op1(int i, int j) {
    printf("1 %d %d\n",i,j);
    a[i] += a[j];
}
void op2(int i, int j) {
    printf("2 %d %d\n",i,j);
    a[j] -= a[i];
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        printf("%d\n",6 * (n / 2));
        for (int i = 1; i <= n; i += 2) {
            op1(i, i + 1);
            op2(i, i + 1);
            op1(i, i + 1);
            op1(i, i + 1);
            op2(i, i + 1);
            op1(i, i + 1);
        }
        //for (int i = 1; i <= n; i++) printf("%lld ",a[i]);
    }
}