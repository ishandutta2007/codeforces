#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int MOD;
int nums[100];
int next[100];
int pow10[1013];
int pow10k[1013];

int main() {
    scanf("%d%d%d",&n,&k,&MOD);
    pow10[0] = 1;
    pow10k[0] = 1;
    for (int i=1;i<n+13;i++) {
        pow10[i] = ((long long) pow10[i-1]*10)%MOD;
        pow10k[i] = (pow10k[i-1]*10)%k;
    }
    for (int i=1;i<10;i++) nums[i%k]+=1;
    int ans = ((long long) 9*pow10[n-1])%MOD;
    for (int i=1;i<n;i++) {
        for (int j=0;j<k;j++) next[j] = 0;
        for (int j=1;j<k;j++) for (int l=0;l<10;l++) if (l!=0 || i!=n-1) next[(j+pow10k[i]*l)%k] = (next[(j+pow10k[i]*l)%k]+nums[j])%MOD;
        for (int j=1;j<10;j++) next[(pow10k[i]*j)%k] = (next[(pow10k[i]*j)%k]+1)%MOD;
        for (int j=0;j<k;j++) nums[j] = next[j];
    }
    for (int i=1;i<k;i++) ans = (ans+MOD-nums[i])%MOD;
    printf("%d\n",ans);

    return 0;
}