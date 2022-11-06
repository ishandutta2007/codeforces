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
    long long k, b, n, t, x, a, ans;
    cin >> k >> b >> n >> t;
    for(a=0, x=1; x<t; x=x*k+b)
        a++;
    ans=n-a;
    if (x>t) ans++;
    if (ans<0) ans=0;
    cout << ans;
}