#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int col[200], val[200];
int cntC[10], cntV[10];
int tVal[200], tCol[200];
int used[10][10];

int getCnt(int a)
{
    int res = 0;
    for (int i = 0; i < 7; i++)
    {
        if (a & (1 << i))
            res++;
    }
    return res;
}
int ind = 0;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        int cc, v;
        scanf(" %c%d", &c, &v);
        v--;
        if (c == 'R')
            cc = 0;
        if (c == 'G')
            cc = 1;
        if (c == 'B')
            cc = 2;
        if (c == 'Y')
            cc = 3;
        if (c == 'W')
            cc = 4;
        if (used[v][cc])
            continue;
        used[v][cc] = 1;
        val[ind] = v;
        col[ind++] = cc;
    }
    int ans = 10;
    for (int maskC = 0; maskC < (1 << 5); maskC++)
        for (int maskN = 0; maskN < (1 << 5); maskN++)
        {
            fill(cntC, cntC + 6, 0);
            fill(cntV, cntV + 6, 0);
            bool ok = true;
            for (int i = 0; i < ind; i++)
            {
                if (maskC & (1 << col[i]))
                    tCol[i] = 1;
                else
                    tCol[i] = 0;
                
                if (maskN & (1 << val[i]))
                    tVal[i] = 1;
                else
                    tVal[i] = 0;
            }
            int cntUn = 0;
            for (int i = 0; i < ind; i++)
            {
                if (tCol[i] && !tVal[i])
                    cntC[col[i]]++;
                if (!tCol[i] && tVal[i])
                    cntV[val[i]]++;
                if (!tCol[i] && !tVal[i])
                    cntUn++;
            }
            if (cntUn > 1)
                ok = false;
            for (int i = 0; i < 5; i++)
            {
                if (cntC[i] > 1 || cntV[i] > 1)
                    ok = false;
            }
            if (!ok)
                continue;
            ans = min(ans, getCnt(maskC) + getCnt(maskN));
        }
    cout << ans;
    
    return 0;
}