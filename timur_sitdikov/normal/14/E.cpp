#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

long long v[21][11][5][5];

int main()
{   
  
    int i, j, v1, v2, v3, n, t;
    long long sum=0;
    scanf("%d %d", &n, &t);
    for(v1=1; v1<4; v1++)
        for(v2=v1+1; v2<5; v2++)
            v[2][0][v1][v2]=1;
    for(i=3; i<=n; i++)
        for(j=0; j<=t; j++)
        {
            for(v1=2; v1<5; v1++)
                for(v2=1; v2<v1; v2++)
                    for(v3=1; v3<5; v3++)
                    {
                        if (v3==v2) continue;
                        v[i][j][v2][v3]+=v[i-1][j][v1][v2];
                    }
            for(v1=1; v1<4; v1++)
                for(v2=v1+1; v2<5; v2++)
                {
                    for(v3=v2+1; v3<5; v3++)
                        v[i][j][v2][v3]+=v[i-1][j][v1][v2];
                    if (j)
                        for(v3=1; v3<v2; v3++)
                            v[i][j][v2][v3]+=v[i-1][j-1][v1][v2];
                }
        }
    for(v1=2; v1<5; v1++)
        for(v2=1; v2<v1; v2++) 
            sum+=v[n][t][v1][v2];
    printf("%lld\n", sum);
}