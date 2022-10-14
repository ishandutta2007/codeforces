#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= n; i ++) 
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

bool ask(int x)
{
        printf("%d\n", x);
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        return ret == 1;
}

void solve()
{
        scanf("%d%d", &n, &k);
        int xr = 0;
        rep(i, n) if(ask(xr ^ i)) break; else xr = xr ^ (xr ^ i);
}

int main()
{
        int T;
        scanf("%d", &T);
        while(T --) solve();
}