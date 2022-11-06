#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

long long dp[55][15];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, f;
    long long ans=0;
    string s;
    cin >> s;
    for(j=0; j<10; j++)
        dp[0][j]=1;
    for(i=0; i<(int)s.length()-1; i++)
        for(j=0; j<10; j++)
        {
            if (!dp[i][j])
                continue;
            if (!((j+s[i+1]-'0')&1))
                dp[i+1][(j+s[i+1]-'0')>>1]+=dp[i][j];
            else
            {
                dp[i+1][(j+s[i+1]-'0')>>1]+=dp[i][j];
                dp[i+1][((j+s[i+1]-'0')>>1)+1]+=dp[i][j];
            }
        }
    for(j=0; j<10; j++)
        ans+=dp[s.length()-1][j];
    f=1;
    for(i=1; i<s.length(); i++)
    {
        j=s[i-1]+s[i]-2*'0';
        if (!(j&1))
        {
            if (s[i]-'0'!=j/2)
            {
                f=0; break;
            }
        }
        else
        {
            if (s[i]-'0'!=j/2 && s[i]-'0'!=j/2+1)
            {
                f=0; break;
            }
        }
    }
    cout << ans-f;
}