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
map <string, ll> used;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,a[105],b[105];
string s,s1;
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
int main()
{
    cin >> n >> m;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> x;
        a[x] = 1;
    }
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> x;
        b[x] = 1;
    }
    for (i = 0; i < 100*n*m; i++)
        if (a[i%n] == 1||b[i%m] == 1)
           a[i%n] = b[i%m] = 1;
    k = 0;
    for (i = 0; i < n; i++)
        k += a[i];
    for (i = 0; i < m; i++)
        k += b[i];
    if (k == n+m)
       cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}