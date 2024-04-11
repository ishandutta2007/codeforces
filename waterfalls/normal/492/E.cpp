#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n,m,dx,dy;
    scanf("%d%d%d%d",&n,&m,&dx,&dy);
    int times[n];
    times[0] = 0;
    int ind = dx;
    for (int i=1;i<n;i++) {
        times[ind] = (times[(ind-dx+n)%n]+dy)%n;
        ind = (ind+dx)%n;
    }
    int sum[n];
    fill(sum,sum+n,0);
    int x,y;
    for (int i=0;i<m;i++) {
        scanf("%d%d",&x,&y);
        y = (y-times[x]+n)%n;
        sum[y]+=1;
    }
    int ans = 0;
    int maxNum = 0;
    for (int i=0;i<n;i++) {
        if (sum[i]>maxNum) {
            ans = i;
            maxNum = sum[i];
        }
    }
    printf("0 %d\n",ans);

    return 0;
}