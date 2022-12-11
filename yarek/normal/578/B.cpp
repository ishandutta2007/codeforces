#include <cstdio>
#include <algorithm>
using namespace std;

long long pref[200002];
long long suf[200002];
int a[200002];

int main()
{
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    long long pow = 1;
    while(k--)
	pow *= x;
    for(int i = 1; i <= n; i++)
    {
	scanf("%d", a + i);
	pref[i] = pref[i-1] | a[i];
    }
    for(int i = n; i >= 1; i--)
	suf[i] = suf[i+1] | a[i];
    long long ans = 0;
    for(int i = 1; i <= n; i++)
	ans = max(ans, pref[i-1] | (a[i] * pow) | suf[i+1]);
    printf("%lld\n", ans);
}