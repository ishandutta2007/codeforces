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

    int vp, vd, t, f, c, ans=0;
    double a, b, eps=1e-8;
    scanf("%d %d %d %d %d", &vp, &vd, &t, &f, &c);
    if (vp>=vd) {printf("0"); return 0;}
    a=t*vp;
    while(a+eps<c)
    {
        
        b=a*vd/(vd-vp);
        if (b+eps>=c) break;
        ans++;
        a=2*b-a+f*vp;
    }
    printf("%d", ans);
}