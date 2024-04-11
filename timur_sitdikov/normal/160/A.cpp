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

    int m[200], n, i, sum=0, sum1=0, ans;
    scanf("%d", &n);
    for(i=0; i<n; i++) 
    {scanf("%d", &m[i]); sum+=m[i];}
    sort(m, m+n);
    for(i=n-1; i>=0; i--)
    {
        sum1+=m[i];
        if (2*sum1>sum) break;
    }
    if (i==-1) i++;
    ans=n-i;
    printf("%d", ans);
}