#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000009
typedef long long ll;
using namespace std;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,max1,t,amnt,a[200500],b[100500];
double real[200500],approx[200500],error[200500],c;
int main()
{
    cin >> n >> t >> c;
    for (i = 0; i < n; i++)
        cin >> a[i];
    approx[0] = ((double)a[0]/t)/c;
    for (i = 1; i < n; i++)
        approx[i] = (approx[i-1] + (double)a[i]/t)/c;
    double tmp = 0;
    for (i = 0; i < t; i++)
        tmp += a[i];
    real[t-1] = (double)tmp/t;
    for (i = t; i < n; i++)
    {
        tmp += a[i]-a[i-t];
        real[i] = (double)tmp/t;
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x;
        printf("%.6f %.6f %.6f\n",real[x-1],approx[x-1],abs(approx[x-1]-real[x-1])/real[x-1]);
    }
    return 0;
}