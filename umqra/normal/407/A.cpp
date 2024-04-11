#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int a, b;
    scanf("%d%d", &a, &b);  

    for (int i = 1; i <= a; i++)
        for (int s = 1; s <= a; s++)
        {
            if (i * i + s * s == a * a)
            {
                int g = gcd(i, s);
                int tx = -s / g;
                int ty = i / g;             
                int l = 0, r = 1002;
                while (r - l > 1)
                {
                    int m = (l + r) / 2;
                    if (m * m * (tx * tx + ty * ty) >= b * b)
                        r = m;
                    else
                        l = m;
                }
                if (r * r * (tx * tx + ty * ty) == b * b)
                {
                    int k = r;
                    int nx = tx * k;
                    int ny = ty * k;
                    if (ny != s)
                    {
                        printf("YES\n0 0\n%d %d\n%d %d", i, s, nx, ny);
                        return 0;
                    }
                }
            }
        }

    puts("NO");
    return 0;
}