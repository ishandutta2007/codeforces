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
    vector <int> ans;
    int i, j, cur, n, a, b, d=50000;
    scanf("%d %d %d", &n, &a, &b);
    if (b==0 && a && a==n-1)  {printf("-1"); return 0;}
    if (!b && a) 
    {
        cur=1;
        ans.push_back(cur);
        ans.push_back(cur);
        j=2;
    }
    else 
    {
        cur=1
            ;
        ans.push_back(cur);
        j=1;
    }
    for(i=0; i<b; i++, j++)
    {
        cur*=2;
        if (cur>d) {printf("-1"); return 0;}
        ans.push_back(cur);
    }
    for(i=0; i<a; i++, j++)
    {
        cur++;
        if (cur>d) {printf("-1"); return 0;}
        ans.push_back(cur);
    }
    for(; j<n; j++)
        ans.push_back(1);
    for(i=0; i<(int)ans.size(); i++)
        printf("%d ", ans[i]);
}