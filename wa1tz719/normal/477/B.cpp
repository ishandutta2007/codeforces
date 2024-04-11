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
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",k*(n*6-1));
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d %d %d %d\n",i*6*k+k,i*6*k+k+k,i*6*k+k+k+k,i*6*k+k+k+k+k+k);
    }
    return 0;
}