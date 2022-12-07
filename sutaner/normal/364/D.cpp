#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define maxn 1000005
#define maxn2 10005
#define LL long long int
using namespace std;
LL line[maxn];
LL fac[maxn2];
int cnt = 0;
LL save[maxn];
int cnt2 = 0;
int sum[maxn];
LL tot = 0;
int n;
LL gcd(LL a, LL b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%I64d", &line[i]);
    }
    for (int random = 0; random < 10; random++){
        cnt = cnt2 = 0;
        memset(sum, 0, sizeof(sum));
        int pos = (rand() % 1000 * 1000 + rand()) % n + 1;
        LL m = line[pos];
        LL con = (LL)sqrt(m);
        if (con * con == m){
            for (LL i = 1; i < con; i++){
                if (m % i == 0){
                    fac[++cnt] = i;
                    fac[++cnt] = m / i;
                }
            }
            fac[++cnt] = con;
        }
        else {
            for (LL i = 1; i <= con; i++){
                if (m % i == 0){
                    fac[++cnt] = i;
                    fac[++cnt] = m / i;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            save[++cnt2] = gcd(m, line[i]);
        }
        sort(save + 1, save + 1 + cnt2);
        LL now;
        for (int i = 1; i <= cnt2; i++){
            now = save[i];
            int ct = 1;
            i++;
            while (i <= cnt2 && save[i] == now) i++, ct++;
            i--;
            for (int j = 1; j <= cnt; j++){
                if (now % fac[j] == 0) sum[j] += ct;
            }
        }
        LL maxnum = -1;
        int judge = (n & 1) ? (n + 1) >> 1 : n >> 1;
        for (int i = 1; i <= cnt; i++){
            if (sum[i] >= judge){
                maxnum = max(maxnum, fac[i]);
            }
        }
        tot = max(tot, maxnum);
    }
    printf("%I64d", tot);
    return 0;
}