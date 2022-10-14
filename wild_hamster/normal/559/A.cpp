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
ll b[200500],a[205205],i,j,n,k,k1,k2,m,x,y,l,r,a1,a2,a3,a4,a5,a6;

int main()
{
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    l = a4;
    ll ans = 0;
    while (a3 && a5)
    {
        r = l+1;
        ans += l+r;
        l = r;
        a3--;
        a5--;
    }
    if (a5)
    {
        while(a5)
        {
            ans += 2*l;
            a5--;
            a2--;
        }
    } else
    while(a3)
    {
        ans += 2*l;
        a3--;
        a6--;
    }
    while (a2)
    {
        r = l-1;
        ans += l+r;
        a2--;
        l = r;
    }
    cout << ans << endl;
    return 0;
}