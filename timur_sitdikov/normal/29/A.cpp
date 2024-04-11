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

const int maxn=105;
int x[maxn], d[maxn];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, n;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> x[i] >> d[i];
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if (x[i]+d[i]==x[j] && x[j]+d[j]==x[i])
            {
                printf("YES");
                return 0;
            }
    printf("NO");
}