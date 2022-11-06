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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m[1005], n, i, ans=0, k;
    cin >> n >> k;
    for(i=0; i<n; i++)
        cin >> m[i];
    sort(m, m+n);
    for(i=0; i<k && m[i]<0; i++)
        ans-=m[i];
    cout << ans;
}