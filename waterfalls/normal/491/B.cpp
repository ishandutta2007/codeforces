#include <cstdio>
#include <algorithm>

using namespace std;

int N,M,C,H;
int pxpy,pxmy,mxpy,mxmy;
int xs[100000];
int ys[100000];

int main() {
    scanf("%d%d%d",&N,&M,&C);
    pxpy = -2147483647;
    pxmy = -2147483647;
    mxpy = -2147483647;
    mxmy = -2147483647;
    for (int i=0;i<C;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        pxpy = max(pxpy,+x+y);
        pxmy = max(pxmy,+x-y);
        mxpy = max(mxpy,-x+y);
        mxmy = max(mxmy,-x-y);
    }
    scanf("%d",&H);
    int best = 2147483647;
    int which = 0;
    for (int i=0;i<H;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        int cur = 0;
        cur = max(cur,pxpy-x-y);
        cur = max(cur,pxmy-x+y);
        cur = max(cur,mxpy+x-y);
        cur = max(cur,mxmy+x+y);
        if (cur<best) {
            best = cur;
            which = i+1;
        }
    }
    printf("%d\n%d\n",best,which);

    return 0;
}