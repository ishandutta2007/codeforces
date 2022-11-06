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

int cmp(const void *c1, const void *c2)
{return *(int*)c1-*(int*)c2;}

bool cmp(int a, int b)
{return a<b;}

int main()
{   

    int i, a, b, c,d,f, ans=0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &f);
    for(i=1; i<=f; i++)
        if ((!(i%a)) || (!(i%b)) || (!(i%c)) || (!(i%d))) ans++;
    printf("%d", ans);

}