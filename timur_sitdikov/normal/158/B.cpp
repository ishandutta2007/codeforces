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

int m[10];

int main()
{   
    int n, i, j, ans=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &j);
        m[j]++;
    }
    ans+=m[4]+m[3];
    m[1]=max(0, m[1]-m[3]);
    ans+=m[2]/2;
    if (m[2]&1)
    {
        ans++;
        m[1]=max(0, m[1]-2);
    }
    ans+=(m[1]+3)/4;
    printf("%d", ans);
}