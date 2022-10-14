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
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, r, md;
string s;
bool isp(ll x)
{
    for (int i = 2; i < x; i++)
        if (x%i == 0)
           return false;
    return true;
}
bool pal(string s)
{
    ll n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] != s[n-i-1])
           return false;
    return true;
}
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    cin >> s;
    cin >> k;
    n = s.size();
    if (n % k != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    ll flag = 1;
    for (i = 0; i < n; i += n/k)
        if (!pal(s.substr(i,n/k)))
           flag = 0;
    if (flag)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}