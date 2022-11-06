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
using namespace std;

char mp[105][105], ans[105][105];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m, n1, m1, a, b, c, i, j, ct, cur=1;
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
    if ((n*m)&1) {printf("IMPOSSIBLE"); return 0;}
    n1=n; m1=m;
    if (n&1)
    {
        for(i=0; i<m; i+=2)
        {
            mp[n-1][i]=mp[n-1][i+1]=cur++;
            ans[n-1][i]=ans[n-1][i+1]=(i+n-1)%26;
        }
        a-=m/2;
        if (a<0) {printf("IMPOSSIBLE"); return 0;}
        n--;
    }
    if (m&1)
    {
        for(i=0; i<n; i+=2)
        {
            mp[i][m-1]=mp[i+1][m-1]=cur++;
            ans[i][m-1]=ans[i+1][m-1]=(i+m-1)%26;
        }
        b-=n/2;
        if (b<0) {printf("IMPOSSIBLE"); return 0;}
        m--;
    }
    ct=n*m/4;
    if (a/2+b/2+c<ct) {printf("IMPOSSIBLE"); return 0;}
    for(i=0; i<n; i+=2)
        for(j=0; j<m; j+=2)
        {
            if (c) 
            {
                mp[i][j]=mp[i+1][j]=mp[i][j+1]=mp[i+1][j+1]=cur++;
                ans[i][j]=ans[i+1][j]=ans[i][j+1]=ans[i+1][j+1]=(i+j)%26;
                c--;
            }
            else if (b>1)
            {
                mp[i][j]=mp[i+1][j]=cur++; mp[i][j+1]=mp[i+1][j+1]=cur++;
                ans[i][j]=ans[i+1][j]=(i+j)%26; ans[i][j+1]=ans[i+1][j+1]=(i+j+1)%26;
                b-=2;
            }
            else
            {
                mp[i][j]=mp[i][j+1]==cur++; mp[i+1][j]=mp[i+1][j+1]=cur++;
                ans[i][j]=ans[i][j+1]=(i+j)%26; ans[i+1][j]=ans[i+1][j+1]=(i+j+1)%26;
                a-=2;
            }
        }
    for(i=0; i<n1; i++)
        for(j=0; j<m1; j++)
            ans[i][j]+='a';
    for(i=0; i<n1; i++)
        printf("%s\n", ans[i]);

}