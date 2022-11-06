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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int a, b, c, s;
    scanf("%d %d %d %d", &s, &a, &b, &c);
    if (!(a+b+c)) {printf("0.0 0.0 %d.0", s); return 0;}
    printf("%.10lf %.10lf %.10lf", s*(a+0.)/(a+b+c), s*(b+0.)/(a+b+c),s*(c+0.)/(a+b+c));
}