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

int main()
{   
    char c1[25], c2[25];
    int i, j, ans, n;
    scanf("%d", &n);
    scanf("%s", &c1);
    ans=strlen(c1);
    for(i=1; i<n; i++)
    {
        scanf("%s", &c2);
        for(j=0; j<ans; j++)
            if (c1[j]!=c2[j]) break;
        ans=j;
    }
    printf("%d", ans);
}