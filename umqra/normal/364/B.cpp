#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

const int MAXS = 500010;

bool exist[MAXS];
int listE[MAXS];
int indE = 0;
int c[100];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif      

    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    
    exist[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int s = MAXS - 1; s >= 0; s--)
        {
            if (exist[s])
                exist[s + c[i]] = 1;
        }
    }

    int cntD = 0;
    int lastS = 0;
    for (int i = 0; i < MAXS; i++)
    {
        if (exist[i])
            listE[indE++] = i;
    }


    for (int i = 0; i < indE; i++)
    {
        if (listE[i] - lastS > d)
        {
            if (lastS != listE[i - 1])
                cntD++;
            lastS = listE[i - 1];   
            if (listE[i] - lastS > d)
                break;
        }
    }
                                                   
    if (listE[indE - 1] - lastS <= d)
    {
        if (lastS != listE[indE - 1])
            cntD++;
        lastS = listE[indE - 1];
    }

    printf("%d %d", lastS, cntD);

    return 0;
}