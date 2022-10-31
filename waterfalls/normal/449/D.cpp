#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[1000013];
int pow2[1000013];
int num[1048576][21];

const int MOD = 1000000007;

int main() {
    pow2[0] = 1;
    for (int i=1;i<1000013;i++) pow2[i] = (pow2[i-1]*2)%MOD;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]), num[a[i]][20]+=1;
    int ans = 0;
    for (int i=19;i>=0;i--) {
        for (int mask=0;mask<(1<<20);mask++) {
            if (mask&(1<<i)) num[mask][i] = num[mask][i+1];
            else num[mask][i] = num[mask][i+1]+num[mask+(1<<i)][i+1];
        }
    }
    for (int mask=1;mask<(1<<20);mask++) {
        int bits = 0;
        for (int i=0;i<20;i++) if (mask&(1<<i)) bits+=1;
        if (bits%2) ans = (ans+pow2[num[mask][0]]-1)%MOD;
        else ans = (ans-pow2[num[mask][0]]+1+MOD)%MOD;
    }
    printf("%d\n",(pow2[n]-1-ans+MOD)%MOD);

    return 0;
}