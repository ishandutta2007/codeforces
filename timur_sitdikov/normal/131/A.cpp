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

int cmp(const void *c1, const void *c2)
{return *(int*)c1-*(int*)c2;}

bool cmp(int a, int b)
{return a<b;}

int main()
{   

    char c[200], d;
    int i, l, f=0;
    scanf("%s", &c);
    l=strlen(c);
    if (l==1)
    {
        d='a'-'A';
        if (c[0]>='a') c[0]-=('a'-'A');
        else c[0]+=d;
        printf("%s", c);
    }
    else
    {
        for(i=1; i<l; i++)
            if (c[i]>='a' && c[i]<='z') 
            {f=1; break;}
        if (!f) d='a'-'A';
        else d=0;
        for(i=0; i<l; i++)
            putchar(c[i]<='Z'? c[i]+d: c[i]-d);
    }
}