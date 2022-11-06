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
    long long a, b, c, ans, i, j;
    cin >> a >> b >> c;
    if (b>c)
        swap(b, c);
    ans=0;
    for(i=0, j=a; i<b; i++, j++)
        ans+=j;
    for(j--; i<c; i++)
        ans+=j;
    for(i=1, j--; i<b; i++, j--)
        ans+=j;
    cout << ans;
    
}