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

string s, ans;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> s;
    int i,j,  l = s.length();
    for(i = 0; i < l; i++)
        if (s[i] == '0')
            break;
    if (i == l)
        i--;
    for(j = 0; j < l; j++)
        if (j != i)
            ans.pb(s[j]);
    cout << ans;
}