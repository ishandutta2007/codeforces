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

const int maxn = 1005;
int v[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, l, r, mx, maxi;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    v[0] = v[n + 1] = 1000000;
    mx = 0;
    for(i = 1; i <= n; i++){
        for(l = i - 1; v[l] <= v[l + 1]; l--);
        for(r = i + 1; v[r] <= v[r - 1]; r++);
        if (r - l - 1 > mx){
            mx = r - l - 1;
            maxi = i;
        }
    }
    cout << mx;

}