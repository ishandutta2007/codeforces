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

const int maxn=1005;
char s[maxn][maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, p;
    cin >> n;
    for(i=0, p=1; ;)
    {
        if (s[i][p])
            break;
        s[i][p]=1;
        i=(i+p)%n;
        p=(p+1)%n;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            if (s[i][j])
                break;
        if (j==n)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}