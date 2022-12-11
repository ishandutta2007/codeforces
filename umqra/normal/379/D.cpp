#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const ll INF = (ll)1e15;

long long getCnt(int k, long long cntA, int fstA, int lstA, long long cntB, int fstB, int lstB)
{
    cntB = min(cntB, INF);
    cntA = min(cntA, INF);
    if (k == 0)
        return cntB;    
    return getCnt(k - 1, cntB, fstB, lstB, cntA + cntB + ((lstA == 0 && fstB == 2) ? 1 : 0), fstA, lstB);
}

bool checkStr(int len, int cnt, int fst, int lst)
{
    if (2 * cnt <= len - 2)
        return true;
    if (2 * cnt == len)
    {
        return (fst == 0 && lst == 2);
    }
    return (fst == 0 || lst == 2);
}

void printStr(int len, int cnt, int fst, int lst)
{
    if (2 * cnt <= len - 2)
    {
        putchar('A' + fst);
        for (int i = 0; i < cnt; i++)
        {
            putchar('A');
            putchar('C');
        }
        for (int i = cnt * 2 + 1; i < len - 1; i++)
            putchar('B');
        putchar('A' + lst);
        return;
    }
    if (2 * cnt == len)
    {
        for (int i = 0; i < cnt; i++)
        {           
            putchar('A');
            putchar('C');           
        }
        return;
    }
    if (fst == 0)
    {
        for (int i = 0; i < cnt; i++)
        {           
            putchar('A');
            putchar('C');
        }
        putchar('A' + lst);
    }
    else
    {
        putchar('A' + fst);
        for (int i = 0; i < cnt; i++)
        {           
            putchar('A');
            putchar('C');
        }
    }        
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int k, x, n, m;
    scanf("%d%d%d%d", &k, &x, &n, &m);
    
    for (int i = 0; i <= n / 2; i++)
        for (int s = 0; s <= m / 2; s++)
        {
            for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) for (int c = 0; c < 3; c++) for (int d = 0; d < 3; d++)
            {
                if (getCnt(k - 2, i, a, b, s, c, d) == x)
                {
                    if (checkStr(n, i, a, b) && checkStr(m, s, c, d))
                    {
                        printStr(n, i, a, b);
                        puts("");
                        printStr(m, s, c, d);
                        return 0;                       
                    }
                }
            }                
        }                          

    puts("Happy new year!");
    return 0;
}