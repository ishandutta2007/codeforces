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
    int x, y, a;
    cin >> x >> y;
    a=(int)sqrt(x*x+y*y+0.1);
    if (x*y>0)
    {
        if (a*a!=x*x+y*y && (a&1))
        {
            printf("white");
        }
        else
        {
            printf("black");
        }
        return 0;
    }
    if (x*y<0)
    {
        if (a*a!=x*x+y*y && (!(a&1)))
        {
            printf("white");
        }
        else
        {
            printf("black");
        }
        return 0;
    }
    printf("black");
}