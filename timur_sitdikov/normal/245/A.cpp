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

int v[3], v1[3];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, i, ind, x, y;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> ind >> x >> y;
        v[ind]+=x;
        v1[ind]+=y;
    }
    for(i=1; i<=2; i++)
        if (v[i]>=v1[i])
            cout << "LIVE" << endl;
        else 
            cout << "DEAD" << endl;
}