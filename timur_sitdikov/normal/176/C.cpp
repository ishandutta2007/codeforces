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

    int n, m, x1, y1, x2, y2, a, b;
    scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);
    a=abs(x1-x2)+1; b=abs(y1-y2)+1;
    if (a<b) swap(a, b);
    if (a>5 || a==5 && b>=4) printf("Second");
    else printf("First");
}