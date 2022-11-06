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

const int maxn = 205;
char cc[maxn][maxn];
int x[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int a, b, c, d, i, di, j, n, cl;
    cin >> a >> b >> c >> d >> n;
    for(i = 0; i < n; i++)
        cin >> x[i + 'a'];
    for(i = 0; i < max(b, d); i++)
        for(j = 0; j < a + c; j++)
            cc[i][j] = '.';
    if (a&1)
    {
        i = b - 1;
        di = -1;
    }
    else
    {
        i = 0;
        di = 1;
    }
    j = 0;
    cl = 'a';
    while(1)
    {
        if (j == a + c)
            break;
        if (!x[cl])
        {
            cl++;
        }
        cc[i][j] = cl;
        i += di;
        if (i == -1)
        {
            j++;
            i = 0;
            di = -di;
        }
        else if (j < a && i == b)
        {
            j++;
            i = b - 1;
            di = -di;
        }
        else if (j >= a && i == d)
        {
            j++;
            i = d - 1;
            di = -di;
        }
        x[cl]--;
    }
    printf("YES\n");
    for(i = 0; i < max(b, d); i++)
        printf("%s\n", cc[i]);
}