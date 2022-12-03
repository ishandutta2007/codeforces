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
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    int i;
    int l,r,u,d;
    l=1;
    r=1;
    u=1;
    d=1;
    for (i=0;a[i]!='\0';i++)
    {
        if (a[i]=='1')
        {
            l=0;
            u=0;
        }
        else if (a[i]=='2')
        {
            u=0;
        }
        else if (a[i]=='3')
        {
            u=0;
            r=0;
        }
        else if (a[i]=='4')
        {
            l=0;
        }
        else if (a[i]=='6')
        {
            r=0;
        }
        else if (a[i]=='7')
        {
            l=0;
            d=0;
        }
        else if (a[i]=='9')
        {
            r=0;
            d=0;
        }
        else if (a[i]=='0')
        {
            l=0;
            r=0;
            d=0;
        }
    }
    if (l|r|u|d)
    {
        puts("NO");
    }
    else
    {
        puts("YES");
    }
    return 0;
}