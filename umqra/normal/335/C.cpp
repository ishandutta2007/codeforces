#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

const int N = (int)1e3;
const int MASK = (1 << 4);

int dp[N][MASK];
int mex[N];
int riv[N][2];
int cc = 1;

int getDp(int pos, int m)
{
    if (pos < 0)
        return 0;
    return dp[pos][m];
}

bool check(int x, int y, int r, int mask)
{
    if (x == 0)
    {
        if (mask & (1 << y))
            return false;
    }
    if (x == r - 1)
    {
        if (mask & (1 << (y + 2)))
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int r, n;
    scanf("%d%d", &r, &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;   
        riv[a][b] = 1;
    }

    for (int i = 0; i <= r; i++)
    {
        for (int mask = 0; mask < (1 << 4); mask++)
        {              
            cc++;
            if (i == 0)
                dp[i][mask] = 0;    
            else
            {
                for (int posX = 0; posX < i; posX++)
                {
                    for (int posY = 0; posY < 2; posY++)
                    {
                        int curG = 0;
                        if (check(posX, posY, i, mask))
                        {
                            int topMask = (mask & 3);
                            topMask |= (1 << (3 - posY));
                            curG ^= getDp(posX, topMask);
                            int botMask = (mask & 12);
                            botMask |= (1 << (1 - posY));
                            curG ^= getDp(i - posX - 1, botMask);
                            mex[curG] = cc;
                        }
                    }
                }
                for (int t = 0;;t++)
                {
                    if (mex[t] != cc)
                    {           
                        dp[i][mask] = t;
                        break;
                    }
                }
            }
        }
    }

    int ans = 0;
    int curMask = 0;
    int last = -1;
    for (int i = 0; i < r; i++)
    {                     
        for (int s = 0; s < 2; s++)
        {
            if (i == 0 && riv[i][s])
            {
                curMask |= (1 << (1 - s));    
                last = 0;
            }
            else if (riv[i][s])
            {
                curMask |= (1 << (3 - s));
                ans ^= dp[i - last - 1][curMask];
                curMask = 0;
                curMask |= (1 << (1 - s));
                last = i;
            }
        }    
    }                                      

    if (last != r - 1)
        ans ^= dp[r - last - 1][curMask];

    if (ans)
        puts("WIN");
    else
        puts("LOSE");

    return 0;
}