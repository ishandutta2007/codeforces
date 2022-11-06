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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, m, s, ans, a, b;
    cin >> n >> m >> s;
    a=n%s;
    if (!a)
        a+=s;
    b=m%s;
    if (!b)
        b+=s;
    ans=a*b*((n-1)/s+1)*((m-1)/s+1);
    cout << ans;
}