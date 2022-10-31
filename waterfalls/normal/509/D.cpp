#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int w[100][100];
int a[100];
int b[100];

int gcd(int a, int b) {
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&w[i][j]);
    int k = 0;
    for (int i=1;i<n;i++) for (int j=1;j<m;j++) k = gcd(k,abs(w[i][j]-w[i][j-1]-w[i-1][j]+w[i-1][j-1]));
    if (k==0) k = 1000000007;
    int ok = 1;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (w[i][j]>=k) ok = 0;
    for (int i=0;i<n;i++) a[i] = w[i][0];
    for (int j=0;j<m;j++) b[j] = ((long long) w[0][j]-a[0]+k)%k;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (((long long) a[i]+b[j]-w[i][j])%k) ok = 0;
    if (ok) {
        printf("YES\n%d\n",k);
        for (int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
        for (int j=0;j<m;j++) printf("%d ",b[j]);
        printf("\n");
    } else printf("NO\n");

    return 0;
}