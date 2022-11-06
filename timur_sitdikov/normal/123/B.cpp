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
    long long x1, y1, x2, y2, a, b, d1, d2, d3, d4, ans;
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &a, &b, &x1, &y1, &x2, &y2);
    d1=(x1+y1)/(2*a); if (x1+y1<0 && ((x1+y1)%(2*a))) d1--;
    d2=(x2+y2)/(2*a); if (x2+y2<0 && ((x2+y2)%(2*a))) d2--;
    d1-=d2;
    if (d1<0) d1=-d1;
    d3=(x1-y1)/(2*b); if (x1-y1<0 && ((x1-y1)%(2*b))) d3--;
    d4=(x2-y2)/(2*b); if (x2-y2<0 && ((x2-y2)%(2*b))) d4--;
    d3-=d4;
    if (d3<0) d3=-d3;
    ans=max(d1, d3);
    printf("%I64d", ans);
}