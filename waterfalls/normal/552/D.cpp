#include <cstdio>
#include <algorithm>

using namespace std;
int x[2013];
int y[2013];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    long long ans = (long long) n*(n-1)*(n-2)/6;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                if ((x[j]-x[i])*(y[k]-y[j])==(x[k]-x[j])*(y[j]-y[i])) ans-=1;
            }
        }
    }
    printf("%I64d\n",ans);

    return 0;
}