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
char a[205];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    int i,j;
    int sum=0;
    for (i=0;a[i]!='\0';i++)
    {
        for (j=i;a[j]!='\0';j++)
        {
            int x=0,y=0;
            int k;
            for (k=i;k<=j;k++)
            {
                if (a[k]=='L') x++;
                if (a[k]=='R') x--;
                if (a[k]=='U') y++;
                if (a[k]=='D') y--;
            }
            if ((x==0)&&(y==0)) sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}