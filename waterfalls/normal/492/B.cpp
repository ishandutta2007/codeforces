#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n,l;
    scanf("%d%d",&n,&l);
    int lanterns[n];
    for (int i=0;i<n;i++) scanf("%d",&lanterns[i]);
    sort(lanterns,lanterns+n);
    double where = 0;
    double d = 0;
    for (int i=0;i<n;i++) {
        if (where>=lanterns[i]-d) {
            where = lanterns[i]+d;
            continue;
        }
        double add = lanterns[i]-where;
        if (i!=0) add = min(add,(lanterns[i]-lanterns[i-1])/2.);
        d = max(d,add);
        where = lanterns[i]+d;
    }
    d = max(d,(double) l-lanterns[n-1]);
    printf("%1.12f\n",d);

    return 0;
}