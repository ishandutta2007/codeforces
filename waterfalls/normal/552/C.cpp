#include <cstdio>
#include <algorithm>

using namespace std;

int w,m;

inline bool go(long long on, long long l, long long r) {
    if (l==r) return true;
    if (on>4e9) return false;
    if (go(on*w,l,r)) return true;
    if (go(on*w,l+on,r)) return true;
    if (go(on*w,l,r+on)) return true;
    return false;
}

int main() {
    scanf("%d%d",&w,&m);
    if (w<=3) printf("YES\n");
    else printf("%s\n",go(1,m,0) ? "YES" : "NO");

    return 0;
}