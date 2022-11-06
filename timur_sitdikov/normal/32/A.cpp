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
#define pb push_back

int m[1005];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, d, ans=0;
    cin >> n >> d;
    for(i=0; i<n; i++)
        cin >> m[i];
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if (abs(m[j]-m[i])<=d)
                ans+=2;
    cout << ans;
}