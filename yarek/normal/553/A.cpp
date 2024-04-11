#include <cstdio>

int newton[1001][1001];
const int mod = 1000000007;

int main()
{
    for(int i = 0; i <= 1000; i++)
    {
	newton[i][0] = newton[i][i] = 1;
	for(int j = 1; j < i; j++)
	    newton[i][j] = (newton[i-1][j-1] + newton[i-1][j]) % mod;
    }
    int c, sum = 0;
    scanf("%d", &c);
    long long ans = 1;
    while(c--)
    {
	int a;
	scanf("%d", &a);
	ans = ans * newton[sum+a-1][sum] % mod;
	sum += a;
    }
    printf("%lld\n", ans);
}