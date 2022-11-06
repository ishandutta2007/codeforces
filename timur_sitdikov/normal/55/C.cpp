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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, i, x, y;
    cin >> n >> m >> k;
    for(i=0; i<k; i++)
    {
        cin >> x >> y;
        if (x<=5 || y<=5 || x>=n-4 || y>=m-4)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}