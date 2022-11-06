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

int m[100][100], top[100];
vector<int> v;

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int a, b, n, i, j, x, y;
    scanf("%d", &n);
    for(i=1; i<n*(n-1)/2; i++)
    {
        scanf("%d %d", &a, &b);
        m[a][b]=1;
        top[a]++; top[b]++;
    }
    for(i=1; i<=n; i++) if (top[i]<n-1) v.push_back(i);
    x=v[0]; y=v[1];
    for(i=1; i<=n; i++)
        if (m[x][i] && m[i][y]) {printf("%d %d", x, y); return 0;}
        printf("%d %d", y, x);
}