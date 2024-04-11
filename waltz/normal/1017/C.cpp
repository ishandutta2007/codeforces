#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int k=sqrt(n-1);
    k++;
    int i;
    for (i=0;i<k;i++)
    {
        int j;
        for (j=k;j>0;j--)
        {
            if (i*k+j<=n)
            {
                printf("%d ",i*k+j);
            }
        }
    }
    return 0;
}