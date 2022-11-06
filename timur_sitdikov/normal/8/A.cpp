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

char c[100005], c1[100005], v1[105], v2[105];
int l;

int check()
{
    int i, j, l1, l2, f;
    l1=strlen(v1); l2=strlen(v2);
    for(i=0; i<=l-l1; i++)
    {
        f=0;
        for(j=0; j<l1; j++)
            if (c[i+j]!=v1[j])
            {f=1; break;}
        if (!f) break;
    }
    i+=l1;
    for(; i<=l-l2; i++)
    {
        f=0;
        for(j=0; j<l2; j++)
            if (c[i+j]!=v2[j])
            {f=1; break;}
        if (!f) return 1;
    }
    return 0;
}

int main()
{   
    int f1, f2, i;
    scanf("%s %s %s", &c, &v1, &v2);
    l=strlen(c);
    f1=check();
    for(i=0; i<l; i++)
        c1[i]=c[i];
    for(i=0; i<l; i++)
        c[i]=c1[l-1-i];
    f2=check();
    if (f1 && f2) {printf("both"); return 0;}
    if (f1) {printf("forward"); return 0;}
    if (f2) {printf("backward"); return 0;}
    printf("fantasy");

}