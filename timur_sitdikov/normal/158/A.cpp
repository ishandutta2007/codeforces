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
    int n, k, i, m[105];
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++)
        scanf("%d", &m[i]);
    if (m[k-1])
        for(i=k; i<n && m[i]==m[k-1]; i++);
    else 
    {
        for(i=k-1; i>=0 && !m[i]; i--);
        i++;
    }
    printf("%d", i);
}