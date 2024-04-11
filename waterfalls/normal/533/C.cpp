#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int xp,yp,xv,yv;

int main() {
    scanf("%d%d%d%d",&xp,&yp,&xv,&yv);
    int p = 0;
    while ((xp!=0 || yp!=0) && (xv!=0 || yv!=0) && !p) {
        if (xp==0) yp-=1;
        else if (yp==0) xp-=1;
        else {
            int what = xv-yv;
            if (xp-yp>xv-yv) xp-=1;
            else yp-=1;
        }
        if (xv==0) {
            if (xp==0 && yv-1==yp) p = 1;
            else yv-=1;
        } else if (yv==0) {
            if (yp==0 && xv-1==xp) p = 1;
            else xv-=1;
        } else if (xv-1==xp && yv-1==yp) p = 1;
        else xv-=1, yv-=1;
    }
    if ((xp==0 && yp==0) || p) printf("Polycarp\n");
    else printf("Vasiliy\n");

    return 0;
}