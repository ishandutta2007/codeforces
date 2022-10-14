#include <omp.h>
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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
typedef long long ll;
using namespace std;
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, op[1000500], md, a[100050];
ll x,y;
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    ll max1 = a[0];
    ll ans = 0;
    for (i = 1; i < n; i++)
    if (a[i] <= max1)
    {
        ans += max1 + 1 - a[i];
        a[i] = max1 + 1;
        max1 = a[i];
    } else
    max1 = a[i];
    cout << ans << endl;
    return 0;
}