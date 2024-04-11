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

int ant[5000005], m[1000005];
char c[5000005];

int main()
{   
    int n, i, j, f, lim=22, num=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
        c[m[i]]=1;
    }
    for(i=1; i<(1<<lim); i++)
        if (c[i]) ant[i]=i;
        else
            for(j=0; j<lim; j++)
                if ((i&(1<<j)) && ant[i^(1<<j)])
                {ant[i]=ant[i^(1<<j)]; break;}
    for(i=lim; i<32; i++)
        num+=(1<<i);
    for(i=0; i<n; i++)
    {
        f=(~m[i])^num;
        printf("%d ", ant[f]? ant[f]: -1);
    }

}