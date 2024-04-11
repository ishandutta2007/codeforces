#include <cstdio>
#include <algorithm>
using namespace std;
const int C_MAX = 1000000010;
struct rec{
    int xm = -C_MAX, xM = C_MAX, ym = -C_MAX, yM = C_MAX;
    rec &cross(const rec &A) {
        xm = max(xm, A.xm);
        ym = max(ym, A.ym);
        xM = min(xM, A.xM);
        yM = min(yM, A.yM);
        return *this;
    }
    bool valid() {
        return xm <= xM && ym <= yM;
    }
} in[150001], l[150001], r[150001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d%d%d%d", &in[i].xm, &in[i].ym, &in[i].xM, &in[i].yM);
    for(int i=1; i<=n; i++) (l[i] = in[i]).cross(l[i-1]);
    for(int i=n; i>=1; i--) (r[i] = in[i]).cross(r[i+1]);
    for(int i=1; i<=n; i++) {
        if(l[i-1].cross(r[i+1]).valid()) {
            printf("%d %d\n", l[i-1].xm, l[i-1].ym);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}