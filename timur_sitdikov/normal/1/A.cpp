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
{return 0;}

int main()
{   
 
    long long n, m, a, res;
    scanf("%I64d %I64d %I64d", &n, &m, &a);

    res=((n+a-1)/a)*((m+a-1)/a);
    printf("%I64d\n", res);
}