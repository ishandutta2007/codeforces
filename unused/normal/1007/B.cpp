#include <bits/stdc++.h>
using namespace std;

int divs[100005];
int vtsize[8];
vector<tuple<int, int, int>> triples;

int main()
{
    for (int i = 1; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            if (i == j && __builtin_popcount(i) == 1) continue;
            for (int k = j; k < 8; k++)
            {
                if ((i | j | k) != 7) continue;
                if ((i == k || j == k) && __builtin_popcount(k) == 1) continue;
                triples.emplace_back(i, j, k);
            }
        }
    }

    divs[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        divs[i] = 2;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                int ii = i;
                int X = 1;
                while (ii % j == 0)
                {
                    ii /= j;
                    ++X;
                }

                divs[i] = divs[ii] * X;
                break;
            }
        }
    }
    
    vector<int> vvt(100000);
    iota(vvt.begin(), vvt.end(), 1);
    sort(vvt.begin(), vvt.end(), [](int a, int b){return divs[a] > divs[b];});

    int T;
    scanf("%d",&T);
//    T = 100000;
    
    while (T--)
    {
        int a[3];
        for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
/*        a[0] = vvt[0];
        a[1] = vvt[1];
        a[2] = vvt[2];*/

        for (int F = 1; F < 8; F++)
        {
            int x = 0;
            for (int j = 0; j < 3; j++)
            {
                if (F & (1 << j)) x = gcd(x, a[j]);
            }

            vtsize[F] = divs[x];
        }

        for (int F = 6; F >= 1; F--)
        {
            for (int X = F + 1; X < 8; X++)
            {
                if ((F & X) == F) vtsize[F] -= vtsize[X];
            }
        }

        long ans = 0;

        for (auto [a, b, c] : triples)
        {
            if (a == b && a == c) ans += (vtsize[a] + 2l) * (vtsize[a] + 1l) * vtsize[a] / 6;
            else if (a == b) ans += (vtsize[a] + 1l) * vtsize[a] * vtsize[c] / 2;
            else if (a == c) ans += (vtsize[a] + 1l) * vtsize[a] * vtsize[b] / 2;
            else if (b == c) ans += (vtsize[b] + 1l) * vtsize[b] * vtsize[a] / 2;
            else ans += vtsize[a] * 1l * vtsize[b] * vtsize[c];
        }
        
        printf("%ld\n", ans);
    }
}