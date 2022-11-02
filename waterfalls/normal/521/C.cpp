#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
char s[100013];
int num[100013];
int MOD = 1000000007;

int modInv(int x) {
    int p = MOD-2;
    int cur = x;
    int ans = 1;
    for (int i=0;i<30;i++) {
        if (p&(1<<i)) ans = ((long long) ans*cur)%MOD;
        cur = ((long long) cur*cur)%MOD;
    }
    return ans;
}

int main() {
    scanf("%d%d %s",&n,&k,&s);
    for (int i=0;i<n;i++) num[i] = s[i]-'0';
    if (k==0) {
        int ans = 0;
        for (int i=0;i<n;i++) {
            ans = ((long long) ans*10)%MOD;
            ans = (ans+num[i])%MOD;
        }
        printf("%d\n",ans);
        return 0;
    }
    int sum = 0;
    for (int i=0;i<n-1;i++) sum+=num[i];
    int binom = 1;
    for (int i=n-1;i>0;i--) binom = ((long long) binom*i)%MOD;
    for (int i=n-k-1;i>0;i--) binom = ((long long) binom*modInv(i))%MOD;
    for (int i=k;i>0;i--) binom = ((long long) binom*modInv(i))%MOD;
    int ans = 0;
    int pow10 = 1;
    for (int i=n-1;i>=k;i--) {
        int now = ((long long) num[i]*pow10)%MOD;
        pow10 = ((long long) pow10*10)%MOD;
        ans = (ans+(long long) now*binom)%MOD;
        binom = ((long long) binom*modInv(i))%MOD;
        binom = ((long long) binom*(i-k))%MOD;
    }
    binom = 1;
    for (int i=n-2;i>0;i--) binom = ((long long) binom*i)%MOD;
    for (int i=n-k-1;i>0;i--) binom = ((long long) binom*modInv(i))%MOD;
    for (int i=k-1;i>0;i--) binom = ((long long) binom*modInv(i))%MOD;
    pow10 = 1;
    for (int i=1;n-i>=k;i++) {
        int now = ((long long) sum*pow10)%MOD;
        pow10 = ((long long) pow10*10)%MOD;
        ans = (ans+(long long) now*binom)%MOD;
        sum-=num[n-i-1];
        binom = ((long long) binom*modInv(n-i-1))%MOD;
        binom = ((long long) binom*(n-k-i))%MOD;
    }
    printf("%d\n",ans);

    return 0;
}