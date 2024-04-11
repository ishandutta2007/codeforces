#include <cstdio>

int tab[1000031];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
	int a;
	scanf("%d", &a);
	tab[a]++;
    }
    int ans = 0;
    for(int i = 0; i <= 1000030; i++)
    {
	ans += tab[i] % 2;
	tab[i+1] += tab[i] / 2;
    }
    printf("%d\n", ans);
}