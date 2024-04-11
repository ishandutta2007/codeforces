#include <cstdio>
#include <algorithm>
using namespace std;

int a[26];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
	scanf("%d", a + i);
    int odd = 0;
    for(int i = 0; i < n; i++)
	if(a[i] % 2) odd++;
    if(odd > 1)
    {
	puts("0");
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < a[i]; j++)
		putchar('a' + i);
    }
    else
    {
	int nwd = a[0];
	for(int i = 1; i < n; i++)
	    if(a[i])
		nwd = __gcd(nwd, a[i]);
	printf("%d\n", nwd);
	if(nwd % 2 == 0) nwd /= 2;
	for(int i = 0; i < nwd; i++)
	{
	    for(int j = 0; j < n; j++)
		for(int k = 0; k < a[j] / 2 / nwd; k++)
		    putchar('a' + j);
	    for(int j = 0; j < n; j++)
		if(a[j] % 2) putchar('a' + j);
	    for(int j = n - 1; j >= 0; j--)
		for(int k = 0; k < a[j] / 2 / nwd; k++)
		    putchar('a' + j);
	}
    }
    puts("");
}