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
    int r, R, r2, n;
    double a, eps=1e-7;
    scanf("%d %d %d", &n, &R, &r);
    if (r>R)
    {printf("NO"); return 0;}
    if (n==1) {printf("YES"); return 0;}
    if (2*r>R)
    {
        printf("NO");
        return 0;
    }
    r2=R-r;
    a=r2*sin(acos(-1.)/(double)n);
    if (a+eps>r) printf("YES");
    else printf("NO");
    return 0;
}