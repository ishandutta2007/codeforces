#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

const int N = (int)5e4 + 10;
const int M = 101;
const int A = 26;

bool used[N][M];
int dp[N][M];
int minPos[N][A];
int n;
char str[N];
int bestLet[N][M];

void calcDp(int pos, int len)
{                          
    if (used[pos][len])
        return;
    if (pos >= n)
    {
        used[pos][len] = 1;
        dp[pos][len] = n;
        return;
    }
    if (len <= 1)
    {
        used[pos][len] = 1;
        dp[pos][len] = pos - (len == 0 ? 1 : 0);
        return;
    }
    used[pos][len] = 1;
    dp[pos][len] = n;
    for (int i = 0; i < A; i++)
    {
        int curPos = minPos[pos][i];
        calcDp(curPos + 1, len - 2);
        int rightPart = dp[curPos + 1][len - 2] + 1;        

        if (dp[pos][len] > minPos[rightPart][i])
        {
            dp[pos][len] = minPos[rightPart][i];
            bestLet[pos][len] = i;
        }
    }                                                        
}

void printAns(int pos, int len)
{
    if (len == 1)               
    {
        printf("%c", str[pos]);
        return;
    }
    if (len == 0)
        return;
    printf("%c", bestLet[pos][len] + 'a');
    printAns(minPos[pos][bestLet[pos][len]] + 1, len - 2);
    printf("%c", bestLet[pos][len] + 'a');
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    n = strlen(str);

    for (int i = n; i < N; i++)
        fill(minPos[i], minPos[i] + A, n);
    for (int i = n - 1; i >= 0; i--)
    {                                 
        for (int s = 0; s < A; s++)
            minPos[i][s] = minPos[i + 1][s];
        minPos[i][str[i] - 'a'] = i;
    }

    int maxAns = 0;
    for (int len = 1; len <= 100; len++)
    {
        calcDp(0, len);            
        if (dp[0][len] != n)
            maxAns = len;
    }
                             
    printAns(0, maxAns);

    return 0;
}