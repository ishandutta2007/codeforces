#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, l, v1, v2, k;

bool check(ld x)
{
    ld dv = 1.0 / v2 - 1.0 / v1;
    ld dst = (x - (ld)l / v1) / dv;
    ld time = dst / v2;
    for(int i = k; i < n; i += k)
    {
	ld dist = time * v1;
	ld left = dst - dist;
	ld meet = left / (v1 + v2), point = dist + meet * v1;
	if(left < 0)
	{
	    meet = left / (v2 - v1);
	    point = dist + meet * v1;
	}
	if(meet + time > x) return false;
	dst = (x - time - meet - (ld)(l - point) / v1) / dv;
	time += meet + dst / v2;
	dst += point;
    }
    return time < x;
}

int main()
{
    scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);
    if(v1 > v2)
    {
	printf("%.10lf\n", (double)((ld)l / v1));
	return 0;
    }
    ld a = 0, b = 1.0 * l / v1;
    for(int i = 0; i < 300; i++)
    {
	ld c = (a + b) / 2;
	if(check(c))
	    b = c;
	else a = c;
    }
    printf("%.10lf\n", (double)a);
}