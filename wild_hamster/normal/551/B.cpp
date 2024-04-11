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
ll w,m,sz,i,n,k,j;
string aa,bb,cc;
ll a[500],d[500],b[500],c[500];
int main()
{
    cin >> aa >> bb >> cc;
    for (i = 0; i < aa.size(); i++)
        a[aa[i]]++;
    for (i = 0; i < bb.size(); i++)
        b[bb[i]]++;
    for (i = 0; i < cc.size(); i++)
        c[cc[i]]++;
    ll min1 = INF;
    for (i = 'a'; i <= 'z'; i++)
        if (b[i] != 0)
           min1 = min(min1,a[i]/b[i]);
    n = min1;
    ll max1 = -1;
    for (i = 0; i <= n; i++)
    {
        for (j = 'a'; j <= 'z'; j++)
            d[j] = a[j] - b[j]*i;
        ll tmp = INF;
        for (j = 'a'; j <= 'z'; j++)
        if (c[j] != 0)
           tmp = min(tmp,d[j]/c[j]);
        if (i + tmp > max1)
        {
            max1 = i+tmp;
            k = i;
            m = tmp;
        }
    }
    for (i = 'a'; i <= 'z'; i++)
        a[i] -= b[i]*k;
    for (i = 'a'; i <= 'z'; i++)
        a[i] -= c[i]*m;
    for (i = 0; i < k; i++)
        cout << bb;
    for (i = 0; i < m; i++)
        cout << cc;
    for (i = 'a'; i <= 'z'; i++)
        for (j = 0; j < a[i]; j++)
            cout << (char)i;
    cout << endl;
    return 0;
}