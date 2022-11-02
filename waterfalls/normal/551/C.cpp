#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int a[100013];
int b[100013];

bool check(long long K) {
    for (int i=1;i<=n;i++) b[i] = a[i];
    long long use = 0;
    for (int i=n;i>=1;i--) {
        if (b[i]==0) continue;
        if (K<=i) return false;
        long long here = (b[i]+K-i-1)/(K-i);
        long long extra = here*(K-i)-b[i];
        int where = i-1;
        while (extra && where) {
            if (b[where]>=extra) {
                b[where]-=extra;
                extra = 0;
            } else {
                extra-=b[where];
                b[where] = 0;
                where-=1;
            }
        }
        use+=here;
    }
    return use<=m;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    long long low = 0;
    long long high = 1e16;
    while (high-low>1) {
        if (check((low+high+1)/2)) high = (low+high+1)/2;
        else low = (low+high+1)/2;
    }
    printf("%I64d\n",high);

    return 0;
}