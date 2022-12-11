#include <cstdio>
#include <algorithm>
using namespace std;

long long fib[51];
const long long inf = 1000000000000000001LL;

int main()
{
    int n;
    scanf("%d", &n);
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= n; i++)
	fib[i] = min(fib[i-1] + fib[i-2], inf);
    long long k;
    scanf("%lld", &k);
    for(int i = 1; i <= n; i++)
	if(k > fib[n-i])
	{
	    k -= fib[n-i];
	    printf("%d %d ", i + 1, i);
	    i++;
	}
	else printf("%d ", i);
    puts("");
}