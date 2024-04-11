#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[1005][1005];
const int modo=1000000007;
int col[1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    c[0][0]=1;
    int i,j;
    for (i=1;i<=1000;i++)
    {
        c[i][0]=1;
        for (j=1;j<=1000;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=modo;
        }
    }
    int k;
    scanf("%d",&k);
    for (i=0;i<k;i++)
    {
        scanf("%d",&col[i]);
        col[i]--;
    }
    int p=1;
    int sum=0;
    for (i=0;i<k;i++)
    {
        sum+=col[i];
        p=(long long)p*c[sum][col[i]]%modo;
        sum++;
    }
    printf("%d\n",p);
    return 0;
}