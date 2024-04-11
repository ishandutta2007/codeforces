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

const int maxn=105;
int a[maxn], b[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, n, mini, f;
    double v, mn;
    cin >> n >> v;
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
        cin >> b[i];
    mini=-1;
    for(i=0; i<n; i++)
    {
        f=0;
        for(j=0; j<n; j++)
        {
            if (a[i]*b[j]<b[i]*a[j])
            {
                f=1;
                break;
            }
        }
        if (!f)
            mini=i;
    }
    mn=0.;
    for(i=0; i<n; i++)
        mn+=a[i]*b[mini]/(a[mini]+0.);
    cout << min(v, mn);
}