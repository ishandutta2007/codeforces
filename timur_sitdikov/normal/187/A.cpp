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

int m[200005], m1[200005], inds[200005];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d", &m1[i]);
        inds[m1[i]]=i;
    }
    for(i=1; i<n; i++)
        if (inds[m[i]]<inds[m[i-1]]) break;
    printf("%d", n-i);
}