#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{   
 
    int n, x, y, i, x0, miny=100000, maxx=-100000;
    scanf("%d %d", &n, &x0);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &x, &y);
        if (x>y) swap(x, y);
        if (x>maxx) maxx=x;
        if (y<miny) miny=y;
    }
    if (miny<maxx) {printf("-1\n"); return 0;}
    if (maxx<=x0 && x0<=miny) {printf("0\n"); return 0;}
    if (x0<maxx) printf("%d\n", maxx-x0);
    if (x0>miny) printf("%d\n", x0-miny);
}