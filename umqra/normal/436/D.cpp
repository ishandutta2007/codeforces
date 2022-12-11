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
#include <ctime>
using namespace std;

const int N = (int)1e5 + 100;
const int MAXC = (int)3e5 + 100;

struct Block
{
    int l, r;
    Block () {}
    Block (int l, int r) : l(l), r(r) {}
    int getLen()
    {
        return r - l + 1;
    }
};
Block listB[N];
int indB = 0;
int x[N], cool[N];
int lenBlockP[MAXC], lenBlockS[MAXC];
int dp[N], maxVal[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    
    for (int s = 0; s < m; s++)
    {
        scanf("%d", &cool[s]);
    }
        
    sort(cool, cool + m);
    sort(x, x + n);
    
    int lst = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] != x[i - 1] + 1)
        {
            listB[indB++] = Block(lst, x[i - 1]);
            lst = x[i];
        }
    }
    listB[indB++] = Block(lst, x[n - 1]);

    int curL = 0;
    for (int i = 0; i < indB; i++)
    {
        curL += listB[i].getLen();
        lenBlockP[curL] = i + 1;
    }
    curL = 0;
    for (int i = indB - 1; i >= 0; i--)
    {
        curL += listB[i].getLen();
        lenBlockS[curL] = i + 1;
    }
    
    for (int i = MAXC - 1; i > 0; i--)
    {
        if (lenBlockP[i] != 0 && lenBlockP[i - 1] == 0)
            lenBlockP[i - 1] = lenBlockP[i];
        if (lenBlockS[i] != 0 && lenBlockS[i - 1] == 0)
            lenBlockS[i - 1] = lenBlockS[i];
    }
    
    int pref = 0;
    int suff = 0;
    for (int i = 0; i < indB; i++) suff += listB[i].getLen();
    
    int ans = 0;
    for (int i = 0; i < indB; i++)
    {
//      cout << listB[i].l << " - " << listB[i].r << endl;
        int cntUnder = 0;
        int valLeft = 0;
        pref += listB[i].getLen();
        int fstInd = m;
        for (int s = 0; s < m; s++)
            if (cool[s] >= listB[i].l)
            {
                fstInd = s;
                break;
            }
        valLeft = max(0, maxVal[i]);
        for (int s = 0; s < m; s++)
        {
            if (cool[s] < listB[i].l)
            {
                int dist = listB[i].l - cool[s];
                int nDist = dist + suff;
                if (nDist < MAXC && lenBlockS[nDist] != 0)
                {
//                  cout << "!!!" << endl;
                    int lenS = lenBlockS[nDist];
                    int curInd = lenS - 1;
                    
                    valLeft = max(valLeft, fstInd - s + maxVal[curInd]);
                    
                }
            }
            else if (cool[s] <= listB[i].r)
                cntUnder++;
            else
                break;
        }
        dp[i] = valLeft + cntUnder;
//      cout << dp[i] << ":" << i << endl;
        maxVal[i + 1] = max(maxVal[i + 1], dp[i]);
//      cout << "DP = " << valLeft << " " << cntUnder  << ":" << i << endl;
        fstInd = m;
        for (int s = 0; s < m; s++)
        {
            if (cool[s] > listB[i].r)
            {
                fstInd = s;
                break;
            }
        }
        ans = max(ans, dp[i]);
        for (int s = fstInd; s < m; s++)
        {
            int dist = cool[s] - listB[i].r;
            int nDist = dist + pref;
            if (nDist < MAXC && lenBlockP[nDist] != 0)
            {
//              cout << "!!" << i << ":" << s << endl;
                int lenP = lenBlockP[nDist];
                int curInd = lenP;
//              cout << s << ":" << fstInd << "  AAA" << endl;
//              cout << "IND = " << curInd << endl;
                maxVal[curInd] = max(maxVal[curInd], dp[i] + (s - fstInd + 1));
                ans = max(ans, maxVal[curInd]);
//              cout << maxVal[curInd] << endl;
            }
        }
        suff -= listB[i].getLen();
        maxVal[i + 1] = max(maxVal[i + 1], maxVal[i]);
    }
    cout << ans;;
    return 0;
}