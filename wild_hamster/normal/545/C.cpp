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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll k,oz,w,l,r,i,j,k1,k2,dr,n,m, qt, qh, md,  x[100500], y[100500], p, a[101005], c[30];
string s,t;
ll ans;
int main()
{
    //freopen("race.in","r",stdin);
    //freopen("race.out","w",stdout);
    cin >> n;
    l = -2LL*MOD;
    for (i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    x[n] = 2LL*MOD;
    for (i = 0; i < n; i++)
    {
        if (x[i]-y[i] > l)
        {
            ans++;
            l = x[i];
        } else
        if (x[i]+y[i] < x[i+1])
        {
            ans++;
            l = x[i] + y[i];
        } else
              l = x[i];
    }
    cout << ans << endl;
    return 0;
}