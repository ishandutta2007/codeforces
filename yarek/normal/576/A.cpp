#include <cstdio>

int y[1000];
bool np[1001];

int main()
{
    int ans = 0, n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
	if(!np[i])
	{
	    for(int j = i; j <= n; j *= i) y[ans++] = j;
	    for(int j = i * i; j <= n; j += i)
		np[j] = true;
	}
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++)
	printf("%d ", y[i]);
    puts("");
}