#include <cstdio>

int n, k;
int tab[2][5] = { { 0, 1, 2, 0, 1 }, { 0, 1, 0, 1, 2 } };

int f(int x)
{
    if(x < 5) return tab[k][x];
    if(x % 2) return 0;
    if(k) return (f(x / 2) & 1) + 1;
    return 1;
}

int main()
{
    scanf("%d %d", &n, &k);
    k %= 2;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
	int a;
	scanf("%d", &a);
	ans ^= f(a);
    }
    puts(ans ? "Kevin" : "Nicky");
}