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

char c[105][105], col[105];

int main()
{   

    int n, m, i, j, k, maxi, f;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
        scanf("%s", &c[i]);
    for(k=0; k<n; k++)
    {
        for(j=0; j<m; j++)
        {
            f=0;
            for(i=0; i<n; i++)
                if (i!=k && c[i][j]>c[k][j]) {f=1; break;}
            if (!f) {col[k]=1; break;}
        }
    }
    maxi=0;
    for(i=0; i<n; i++)
        maxi+=col[i];
    printf("%d", maxi);
}