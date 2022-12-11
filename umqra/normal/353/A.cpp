#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair
const int N = (int)1e5;
int a[N], b[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        sumA += a[i];   
        sumB += b[i];
    }

    if (sumA % 2 == 0 && sumB % 2 == 0)
        puts("0");
    else if (sumA % 2 == 1 && sumB % 2 == 1)
    {
        bool h = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0 && b[i] % 2 == 1)
                h = true;
            if (a[i] % 2 == 1 && b[i] % 2 == 0)
                h = true;
        }
        if (h)
            puts("1");  
        else
            puts("-1");
    }
    else
        puts("-1");

    return 0;
}