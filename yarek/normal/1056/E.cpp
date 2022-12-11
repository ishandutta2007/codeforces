#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const int N = 1000002;
typedef long long ll;
const ll mod = 1000000007;
ll A;
ll powA[N];

char s[N];
char t[N];
bool bs[N];

ll hsh[N];

ll gethash(int a, int b)
{
    ll h = (hsh[b] - hsh[a] * powA[b-a]) % mod;
    if(h < 0) h += mod;
    //printf("gethash(%d %d) = %lld\n", a, b, h);
    return h;
}

int main()
{
    srand(getpid());
    A = rand() % 100000 + 30;
    scanf("%s %s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    if(n > m)
    {
        puts("0");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        bs[i] = s[i] != s[1];
    int one = find(bs, bs + n + 1, true) - bs;
    int ones = count(bs, bs + n + 1, true), zeros = n - ones;
    powA[0] = 1;
    for(int i = 1; i <= m; i++)
    {
        powA[i] = powA[i-1] * A % mod;
        hsh[i] = (hsh[i-1] * A + t[i] - 'a' + 1) % mod;
    }
    //printf("%d %d %d %d\n", zeros, ones, n, m);
    int ans = 0;
    for(int i = 1; i < m; i++)
    {
        int k = i;
        if(k * zeros >= m) break;
        int l = (m - k * zeros) / ones;
        if(k * zeros + l * ones != m) continue;
        ll h0 = gethash(0, k), h1 = gethash(k * (one - 1), k * (one - 1) + l);
        if(h0 == h1) continue;
        bool ok = true;
        for(int i = 1, j = 0; i <= n; i++)
        {
            if(bs[i])
            {
                if(gethash(j, j + l) != h1)
                {
                    ok = false;
                    break;
                }
                j += l;
            }
            else
            {
                if(gethash(j, j + k) != h0)
                {
                    ok = false;
                    break;
                }
                j += k;
            }
        }
        if(ok) ans++;
    }
    printf("%d\n", ans);
}