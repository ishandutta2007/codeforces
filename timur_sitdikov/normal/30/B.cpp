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

int len[13];

struct date
{
    int dd, mm, yy;
};

int is_correct(date d)
{
    if (d.mm>13)
        return 0;
    if (d.dd<=len[d.mm] || d.yy%4==0 && d.mm==2 && d.dd==29)
        return 1;
    return 0;
}

void fill()
{
    len[1]=len[3]=len[5]=len[7]=len[8]=len[10]=len[12]=31;
    len[2]=len[4]=len[6]=len[9]=len[11]=30;
    len[2]=28;
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    date d1, d2;
    int i, m[3], dif;
    scanf("%d.%d.%d%d.%d.%d", &d1.dd, &d1.mm, &d1.yy, &d2.dd, &d2.mm, &d2.yy);
    fill();
    m[0]=d2.dd;
    m[1]=d2.mm;
    m[2]=d2.yy;
    for(i=0; i<6; i++)
    {
        next_permutation(m, m+3);
        d2.dd=m[0];
        d2.mm=m[1];
        d2.yy=m[2];
        if (!is_correct(d2))
            continue;
        if (d1.yy<=d2.yy)
            continue;
        dif=d1.yy-d2.yy-1;
        if (d1.mm>d2.mm || d1.mm==d2.mm && d1.dd>=d2.dd)
            dif++;
        if (dif>=18)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}