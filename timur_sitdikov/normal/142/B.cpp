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
    int n, m, ans;
    scanf("%d %d", &n, &m);
    if (m>n) swap(n, m);
    if (m==1)
    {printf("%d", n); return 0;}
    if (m==2)
    {
        ans=n-n%4;
        if (n%4==1) ans+=2;
        if (n%4>1) ans+=4;
        printf("%d", ans);
        return 0;
    }
    ans=n*m/2+((n*m)&1);
    printf("%d", ans);
}