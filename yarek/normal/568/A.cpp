#include <cstdio>

const int K = 2000001;

int reverse(int x)
{
    int y = 0;
    while(x > 0)
    {
	y *= 10;
	y += x % 10;
	x /= 10;
    }
    return y;
}

bool np[K];

int main()
{
    int p, q;
    scanf("%d %d", &p, &q);
    np[1] = true;
    int pi = 0, pal = 0;
    int ans = K;
    for(int i = 1;; i++)
    {
	if(i - ans > 10000)
	{
	    printf("%d\n", ans);
	    return 0;
	}
	if(reverse(i) == i) pal++;
	if(!np[i]) pi++;
	if(q * pi <= p * pal)
	    ans = i;
	if(!np[i] && i <= 10000)
	    for(int j = i * i; j <= K; j += i)
		np[j] = true;
    }
}