#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int n,T,m;
double c;
int a[200013];
long long sums[200013];
double mean[200013];

int main() {
    scanf("%d%d%lf",&n,&T,&c);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) sums[i] = sums[i-1]+a[i-1];
    for (int i=1;i<=n;i++) mean[i] = (mean[i-1]+1.*a[i-1]/T)/c;
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        int q;
        scanf("%d",&q);
        double real = 1.*(sums[q]-sums[q-T])/T;
        double approx = mean[q];
        double error = fabs(approx-real)/real;
        printf("%1.9f %1.9f %1.9f\n",real,approx,error);
    }

    return 0;
}