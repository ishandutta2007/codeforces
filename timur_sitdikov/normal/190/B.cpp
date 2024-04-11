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

    int x1, y1, x2, y2, r1, r2;
    double d, ans;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+0.);
    if (r1>r2) swap(r1, r2);
    if (d>r1+r2) ans=(d-r1-r2)/2.;
    else if (r2>r1+d) ans=(r2-r1-d)/2.;
    else ans=0.;
    if (ans<0.) ans=0.;
    printf("%.12lf", ans);
}