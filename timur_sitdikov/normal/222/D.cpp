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

const int maxn=100005;
int a[maxn], b[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int x, i, j, n, dif;
    cin >> n >> x;
    for(i=0; i<n; i++)
        cin >> a[i];
    for(j=0; j<n; j++)
        cin >> b[j];
    sort(a, a+n);
    sort(b, b+n);
    i=0;
    j=n-1;
    dif=0;
    for(; i<n; i++)
        if (a[i]+b[j]<x)
        {
            dif++;
        }
        else
            j--;
    cout << 1 << " " << n-dif;

}