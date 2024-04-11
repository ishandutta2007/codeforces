#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;
const int N = 3000;
bool res[N][N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    int t = n * k;
    int p = n * (n - 1) / 2;
    if (t > p)
    {
        cout << -1;
        return 0;
    }   

    for (int i = 1; i <= n; i++)
        for (int s = i + 1; s <= n; s++)
        {                
            if ((i + s) % 2 == 0)
                res[i][s] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int s = 1; s < i; s++)
        {
            if ((i + s) % 2 == 1)
                res[i][s] = 1;
        }

    for (int i = 1; i <= n; i++)
    {
        int c = 0;        
        for (int s = 1; s <= n; s++)
            if (res[i][s])
                c++;
        for (int s = 1; s <= n; s++)
        {
            if (res[i][s] && c > k)
            {
                res[i][s] = 0;
                c--;
            }
        }
    }

    printf("%d\n", t);
    for (int i = 1; i <= n; i++)
        for (int s = 1; s <= n; s++)
            if (res[i][s])
                printf("%d %d\n", i, s);    
    
    return 0;
}