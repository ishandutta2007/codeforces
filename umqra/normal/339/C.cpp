#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair
            
const int N = 1000 + 100; 
const int T = 20;
char str[N];
int listW[N];
int indW;
vector <int> ans;
bool dp[N][21][21];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    scanf("%s", str);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= 10; i++)
    {
        if (str[i - 1] == '1')
            listW[indW++] = i;
    }
                        
    dp[0][0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        int startD = (i == 0 ? 0 : 1);
        for (int s = startD; s <= 20; s++)
        {
            for (int lastG = 0; lastG <= 10; lastG++)
            {
                if (dp[i][s][lastG])
                {
                    for (int curInd = 0; curInd < indW; curInd++)
                    {
                        if (listW[curInd] != lastG && listW[curInd] > s)    
                            dp[i + 1][listW[curInd] - s][listW[curInd]] = 1;
                    }
                }
            }
        }
    }

    int curW = -1, curLast;
    for (int i = 1; i <= 20; i++)
    {             
        for (int s = 1; s <= 10; s++)
            if (dp[m][i][s])
            {
                curW = i;
                curLast = s;
            }
    }                                       
    if (curW == -1)
    {
        puts("NO");
        return 0;
    }
            
    for (int i = m; i > 0; i--)
    {
        ans.push_back(curLast);   
        int nLast;
        for (int t = 1; t <= 10; t++)
        {
            if (t != curLast && dp[i - 1][curLast - curW][t])
            {
                nLast = t;  
                break;
            }
        }
        curW = curLast - curW;
        curLast = nLast;
    }
    puts("YES");
    for (int i = m - 1; i >= 0; i--)
        printf("%d ", ans[i]);
    
    return 0;
}