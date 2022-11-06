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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

int check(int a, int b)
{return b>=a-1 && b<=2*a+2;}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b2 >> b1;
    if (check(a1, b1) || check(a2, b2))
        printf("YES");
    else printf("NO");
}