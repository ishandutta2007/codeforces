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

int m[100005];

int main()
{   
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &m[i]);
    sort(m, m+n);
    if (m[n-1]==1) m[n-1]=2;
    else m[n-1]=1;
    sort(m, m+n);
    for(i=0; i<n; i++)
        printf("%d ", m[i]);
}