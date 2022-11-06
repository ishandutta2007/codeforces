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
    int m[200], a, b, i, n, ans=0;
    cin >> n;
    for(i=1; i<n; i++)
        cin >> m[i];
    cin >> a >> b;
    //a--; b--;
    for(i=a; i<b; i++)
        ans+=m[i];
    
    cout << ans;
}