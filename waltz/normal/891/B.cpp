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
int a[25],b[25];
map<int,int> ma;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    int n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    for (i=0;i<n;i++)
    {
        if ((i!=n-1)&&(b[i]==b[i+1]))
        {
            puts("-1");
            return 0;
        }
        if (i!=0)
        {
            ma[b[i-1]]=b[i];
        }
        else
        {
            ma[b[n-1]]=b[i];
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",ma[a[i]]);
    }
    printf("\n");
    return 0;
}