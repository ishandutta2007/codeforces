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
    int a, i, j, sum=0, n;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d", &a);
            if (i==j || i+j==n-1 || i==(n-1)/2 || j==(n-1)/2) sum+=a;
        }
    printf("%d", sum);
}