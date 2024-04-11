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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

const int maxn = 100005;
int s[maxn], v[2][maxn], top[2], used[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i[2], n, j, col, w, v0, v1;
    scanf("%d", &n);
    for(j = 1; j <= n; j++){
        scanf("%d %d", &col, &s[j]);
        v[col][top[col]++] = j;
    }
    for(i[0] = 0, i[1] = 0; i[0] < top[0] && i[1] < top[1]; ){
        v0 = v[0][i[0]];
        v1 = v[1][i[1]];
        w = min(s[v0], s[v1]);
        used[v0] = used[v1] = 1;
        printf("%d %d %d\n", v0, v1, w);
        s[v0] -= w;
        s[v1] -= w;
        if (s[v0] == 0)
            i[0]++;
        else if (s[v1] == 0)
            i[1]++;
    }
    for(; i[0] < top[0]; i[0]++){
        v0 = v[0][i[0]];
        v1 = v[1][top[1] - 1];
        if (used[v0])
            continue;
        used[v0] = used[v1] = 1;
        printf("%d %d %d\n", v0, v1, 0);
    }
    for(; i[1] < top[1]; i[1]++){
        v0 = v[0][top[0] - 1];
        v1 = v[1][i[1]];
        if (used[v1])
            continue;
        used[v0] = used[v1] = 1;
        printf("%d %d %d\n", v0, v1, 0);
    }
}