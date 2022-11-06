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

int col[100005];

int main()
{   
    int a, b, r0, i, m;
    scanf("%d %d %d %d", &a, &b, &m, &r0);
    for(i=1; !col[r0];r0=(a*r0+b)%m, i++)
    {col[r0]=i;}
    printf("%d", i-col[r0]);
}