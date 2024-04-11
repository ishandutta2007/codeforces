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
ll k,oz,w,l,r,i,j,k1,k2,dr,n,m, qt, qh, md,  x, y, p, a[101005], c[30];
string s,t;
ll ans;
int main()
{
    //freopen("race.in","r",stdin);
    //freopen("race.out","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= k)
        {
            k += a[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}