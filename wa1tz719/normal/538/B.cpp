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
int a[15];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int t=0;
    for (i=0;n!=0;i++)
    {
        a[i]=n%10;
        n/=10;
        t=max(t,a[i]);
    }
    int len=i;
    printf("%d\n",t);
    int j;
    for (i=0;i<t;i++)
    {
        for (j=len-1;j>=0;j--)
        {
            if (a[j]>0)
            {
                a[j]--;
                j--;
                printf("1");
                break;
            }
        }
        for (;j>=0;j--)
        {
            if (a[j]>0)
            {
                a[j]--;
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}