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
    int i;
    int r=0,g=0,b=0;
    for (i=0;i<n;i++)
    {
        if (a[i]=='R') r++;
        if (a[i]=='G') g++;
        if (a[i]=='B') b++;
    }
    if ((r==0)+(g==0)+(b==0)==2)
    {
        if (r!=0) putchar('R');
        if (g!=0) putchar('G');
        if (b!=0) putchar('B');
        return 0;
    }
    else if ((r==0)+(g==0)+(b==0)==1)
    {
        if (r==0)
        {
            if (g>1) putchar('B');
            if (b>1) putchar('G');
            putchar('R');
        }
        if (g==0)
        {
            if (r>1) putchar('B');
            putchar('G');
            if (b>1) putchar('R');
        }
        if (b==0)
        {
            putchar('B');
            if (r>1) putchar('G');
            if (g>1) putchar('R');
        }
    }
    else
    {
        puts("BGR");
    }
    return 0;
}