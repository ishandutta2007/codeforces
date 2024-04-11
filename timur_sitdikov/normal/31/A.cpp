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

int a[105];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, k, n;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> a[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            for(k=1; k<+n; k++)
            {
                if (a[i]==a[j]+a[k] && i!=j && j!=k && i!=k)
                {
                    printf("%d %d %d", i, j, k);
                    return 0;
                }
            }
    printf("-1");
}