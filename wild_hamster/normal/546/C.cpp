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
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, op[100050], md;
ll x,y;
queue <ll> a,b;
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    cin >> n;
    cin >> k1;
    for (i = 0; i < k1; i++)
    {
        cin >> x;
        a.push(x);
    }
    cin >> k2;
    for (i = 0; i < k2; i++)
    {
        cin >> x;
        b.push(x);
    }
    ll tmp = 0;
    while (tmp < 1048577 && !a.empty() && !b.empty())
    {
        x = a.front();
        y = b.front();
        a.pop();
        b.pop();
        if (x > y)
        {
            a.push(y);
            a.push(x);
        } else
        {
            b.push(x);
            b.push(y);
        }
        tmp++;
    }
    if (tmp == 1048577)
       cout << -1 << endl;
    else
    {
        if (a.empty())
           cout << tmp << " " << 2 << endl;
        else
            cout << tmp << " " << 1 << endl;
    }
    return 0;
}