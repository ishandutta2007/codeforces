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
#define pb push_back

char c[305][305];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, i, j, l, cur=0;
    cin >> n >> m >> k;
    for(i=0; i<n; i++)
        scanf("%s", &c[i]);
    for(l=1; l<n; l++)
    {
        for(i=l; i<n-l; i++)
            for(j=l; j<m-l; j++)
                if (c[i][j]=='*' && c[i-l][j]=='*' && c[i][j-l]=='*' &&
                    c[i+l][j]=='*' && c[i][j+l]=='*')
                {
                    cur++;
                    if (cur==k)
                    {
                        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", 
                            i+1, j+1, i-l+1, j+1, i+l+1, j+1, i+1, j-l+1, i+1, j+l+1);
                        return 0;
                    }
                }
    }
    printf("-1");
}