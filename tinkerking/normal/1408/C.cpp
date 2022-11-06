#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, L;
int a[100010];
double t[100010][2];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&L);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        a[0] = 0;
        a[N+1] = L;
        t[0][0] = 0;
        for (int i=1;i<=N+1;i++) t[i][0] = t[i-1][0] + 1.0 * (a[i] - a[i - 1]) / i;
        t[N+1][1] = 0;
        for (int i=N;i>=0;i--) t[i][1] = t[i + 1][1] + 1.0 * (a[i + 1] - a[i]) / (N - i + 1);
        bool fd = false;
        for (int i=1;i<=N;i++) {
            if (fabs(t[i][0] - t[i][1]) < 1e-8) {
                printf("%.10lf\n", t[i][0]);
                fd = true;
                break;
            }
        }
        /*
        for (int i=0;i<=N+1;i++) {
            printf("%d %.5lf %.5lf\n",i,t[i][0],t[i][1]);
        }
        */
        if (fd) continue;
        for (int i=0;i<=N;i++) {
            int v1 = i+1;
            int v2 = N+1-i;
            if (t[i+1][1] > t[i][0] - 1e-8 && t[i+1][1] < t[i+1][0] + 1e-8) {
                double d = a[i+1]-a[i]-v1*(t[i+1][1]-t[i][0]);
                double tt = d/(v1+v2);
                printf("%.10lf\n",t[i+1][1] + tt);
                fd = true;
                break;
            }
            if (t[i][0] > t[i+1][1] - 1e-8 && t[i][0] < t[i][1] + 1e-8) {
                double d = a[i+1]-a[i]-v2*(t[i][0]-t[i+1][1]);
                double tt =d/(v1+v2);
                printf("%.10lf\n",t[i][0] + tt);
                fd = true;
                break;
            }
        }
        assert(fd);
    }
}