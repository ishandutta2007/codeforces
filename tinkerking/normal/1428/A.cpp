#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        LL ans = 0;
        if (x1 == x2 || y1 == y2) {
            ans = abs(x1 - x2) + abs(y1 - y2);
        } else {
            ans = abs(x1 - x2) + abs(y1 - y2) + 2;
        }
        printf("%lld\n",ans);
    }
}