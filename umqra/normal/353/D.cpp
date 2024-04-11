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

const int N = (int)1e6;
char str[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
                   
    scanf("%s", str);
    int n = strlen(str);
    int cntS = 0;
    int cntM = 0, cntF = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'M')
            cntM++;
        else
            cntF++;
    }

    if (cntM == 0 || cntF == 0)
    {
        puts("0");
        return 0;
    }

    int ans = 0;
    int t = 0;
    int cntZ = 0;
    int cntStop = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'F')
        {                                   
            t++;
            cntZ++;
        }
        else
        {
            if (cntStop >= t && cntZ != t)
                cntStop = cntStop - t + 1;
            else
                cntStop = 0;
            ans = max(ans, cntZ + cntStop);
            t = 0;
        }
    }

    cout << ans;
    return 0;
}