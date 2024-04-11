#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        LL x, y;
        scanf("%lld%lld",&x,&y);
        if (y < x) {
            printf("%lld\n",x + y);
        } else {
            printf("%lld\n",y - (y - x) % x / 2);
        }
    }
}