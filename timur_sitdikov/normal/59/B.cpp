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

int a[105];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, mn, ans=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        ans+=a[i];
    }
    if (!(ans&1))
    {
        mn=1000;
        for(i=0; i<n; i++)
            if ((a[i]&1) && a[i]<mn)
                mn=a[i];
        if (mn==1000)
        {
            ans=0;
        }
        else ans-=mn;
    }
    cout << ans;
    


}