#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int c, d;
        scanf("%d%d",&c,&d);
        if (c % 2 != d % 2) {
            puts("-1");
            continue;
        }
        if (c == 0 && d == 0) {
            puts("0");
            continue;
        }
        if (c == d) {
            puts("1");
            continue;
        } else {
            puts("2");
        }
    }
}