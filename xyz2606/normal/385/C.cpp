#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
bool f[10000001];
int prime[10000001], md[10000001], s[10000001], n, x, y, le, ri, np, m, ans[10000001];
int main()
{
    memset(f, true, sizeof(f));
    prime[0] = 0x7fffffff;
    for(int i = 2; i <= 10000000; i++)
    {
        if(f[i]) {prime[++np] = i; md[i] = np;}
        for(int j = 1; j <= np and i * prime[j] <= 10000000 and i % prime[j - 1]; j++)
            f[i * prime[j]] = false, md[i * prime[j]] = j;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        while(x != 1)
        {
            ans[md[x]]++;
            y = prime[md[x]];
            while(x % y == 0) x /= y;
        }
    }
    s[0] = 0;
    for(int i = 1; i <= np; i++) s[i] = s[i - 1] + ans[i];
    s[np + 1] = s[np];
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        le = lower_bound(prime + 1, prime + 1 + np, x) - prime;
        ri = upper_bound(prime + 1, prime + 1 + np, y) - prime - 1;
        
        printf("%d\n", s[ri] - s[le - 1]);
    }
    fclose(stdin);
    return 0;
}