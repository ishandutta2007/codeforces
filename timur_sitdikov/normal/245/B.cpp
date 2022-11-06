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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int i, n;
    string s, ans;
    cin >> s;
    n=s.length();
    if (s[0]=='h')
    {
        ans="http://";
        i=5;
    }
    else
    {
        ans="ftp://";
        i=4;
    }
    ans.pb(s[i-1]);
    for(; i<n; i++)
        if (s[i]=='r' && s[i+1]=='u')
            break;
        else
            ans.pb(s[i]);
    ans+=".ru";
    i+=2;
    if (i<n)
    {
        ans.pb('/');
        for(; i<n; i++)
            ans.pb(s[i]);
    }
    cout << ans;
}