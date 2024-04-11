#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int v1,v2,t,d;

int main() {
    scanf("%d%d%d%d",&v1,&v2,&t,&d);
    int cur = v1;
    int dist = 0;
    for (int T=0;T<t;T++) {
        dist+=cur;
        int left = (t-1)-(T+1);
        int upper = v2+left*d;
        int change = upper-cur;
        cur+=min(upper-cur,d);
    }
    printf("%d\n",dist);

    return 0;
}