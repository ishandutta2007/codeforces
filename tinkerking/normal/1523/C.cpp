#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, a[1010];
int tp;
pii stk[1010];

void print() {
    printf("%d",stk[1].first);
    for (int i = 2; i <= tp; i++) {
        printf(".%d",stk[i].first);
    }
    puts("");
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        stk[0] = pii(0, 1);
        stk[tp = 1] = pii(1, 0);
        print();
        for (int i = 2; i <= n; i++) {
            while(stk[tp].second != a[i] - 1) tp--;
            stk[tp].second++;
            stk[++tp] = pii(a[i], 0);
            print();
        }
    }
}