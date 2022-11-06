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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> ans;
    int i, n;
    cin >> n;
    for(i=n; i>1; i-=2)
    {ans.pb(i-1); ans.pb(i);}
    if (i==1)
        ans.pb(1);
    for(i=n-1; i>=0; i--)
        cout << ans[i] << " ";
}