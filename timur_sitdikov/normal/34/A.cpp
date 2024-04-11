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
    int m[1005], n, i, j, mn=1000000, mini;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> m[i];
    for(i=0; i<n; i++)
        if (abs(m[i]-m[(i+1)%n])<mn)
        {
            mn=abs(m[i]-m[(i+1)%n]);
            mini=i;
        }
    cout << mini+1 << " " << (mini+1)%n+1;
}