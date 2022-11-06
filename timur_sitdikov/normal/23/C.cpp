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

struct box
{
    int n;
    long long a, b;
};

const int maxn=200005;
box bx[maxn];

bool cmp(box& bx1, box& bx2)
{
    return bx1.a<bx2.a;
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int t, i, j, n;
    long long s[2];
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> n;
        for(j=0; j<2*n-1; j++)
        {
            cin >> bx[j].a >> bx[j].b;
            bx[j].n=j+1;
        }
        sort(bx, bx+2*n-1, cmp);
        s[0]=s[1]=0;
        for(j=0; j<2*n-2; j++)
            s[j&1]+=bx[j].b;
        printf("YES\n");
        if (s[0]>s[1])
            j=0;
        else j=1;
        for(; j<2*n-2; j+=2)
            printf("%d ", bx[j].n);
        printf("%d\n", bx[2*n-2].n);
    }
}