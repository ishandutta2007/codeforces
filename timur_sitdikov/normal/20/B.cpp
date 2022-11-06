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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    long long a, b, c, d, top=0, i;
    double ans[5];
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    if (!a)
    {
        if (!b)
        {if (!c) top=-1;}
        else
        {ans[top++]=(double)(-c)/(double)(b);}
    }
    else
    {
        d=b*b-a*c*4;
        if (d<0) top=0;
        else if (!d){
            ans[top++]=(double)(-b)/(double)(2*a);
        }
        else
        {
            ans[top++]=((double)(-b)-sqrt((double)d))/(double)(2*a);
            ans[top++]=((double)(-b)+sqrt((double)d))/(double)(2*a);
        }
    }
    printf("%I64d\n", top);
    if (top==2 && ans[0]>ans[1])
        swap(ans[0], ans[1]);
    for(i=0; i<top; i++)
        if (fabs(ans[i])<1e-7) ans[i]=0.000000000;
    for(i=0; i<top; i++)
        printf("%.8lf\n", ans[i]);

}