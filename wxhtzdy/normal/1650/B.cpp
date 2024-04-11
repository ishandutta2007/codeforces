#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int l, r, a;

int f(int x)
{
    if(x < 0) return 0;
    return x / a + x % a;
}

void solve()
{
    scanf("%d%d%d", &l, &r, &a);
    printf("%d\n", max(f(r), f(max(l, r - r % a - 1))));
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}