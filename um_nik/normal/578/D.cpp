#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;

const int N = 100100;
char s[N];
ll a[N];
ll b[N];
int n;
ll m;
ll ans = 0;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%lld", &n, &m);
    scanf(" %s ", s);
    m--;
    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1])
            b[i] = 1;
    b[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        b[i] += b[i + 1];
    ans = 0;
    for (int i = 0; i < n; i++)
        ans += m * (b[i + 1] + 1);
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < n - 1; i++)
        if (s[i] != s[i + 1])
            b[i + 1] = 1;
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    for (int i = 1; i < n; i++)
        ans += m * b[i];
    
    int r = 0;
    for (int l = 0; l < n - 1; l++)
    {
        if (s[l] == s[l + 1]) continue;
        r = max(r, l + 2);
        while(r < n && s[r] == s[r - 2]) r++;
        ans -= r - l - 1;
    }
    
    printf("%lld\n", ans);

    return 0;
}