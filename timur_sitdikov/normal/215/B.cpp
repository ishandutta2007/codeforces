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

const int maxn=5005;
double x[maxn], y[maxn], z[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, i, j;
    double mx=0., a, b, r1=0., tmp;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x[i];
        if (x[i]>r1)
            r1=x[i];
    }
    cin >> m;
    for(i=0; i<m; i++)
        cin >> y[i];
    cin >> k;
    for(i=0; i<k; i++)
        cin >> z[i];
    cin >> a >> b;
    for(i=0; i<m; i++)
        for(j=0; j<k; j++)
        {
            tmp=r1*r1*b*y[i]/(a*z[j]+b*y[i]);
            if (tmp>mx)
                mx=tmp;
        }
    mx=sqrt(mx);
    printf("%.12lf", mx);

}