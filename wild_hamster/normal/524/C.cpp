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
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,dr,a[100005];
set <ll> f;
map <ll,ll> b;
int main()
{
    cin >> n >> k;
    b[0] = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        for (j = 1; j <= k; j++)
        if (b.find(a[i]*j) != b.end())
            b[a[i]*j] = min(b[a[i]*j],j);
        else
            b[a[i]*j] = j;
    }
    cin >> q;
    for (int ii = 0; ii < q; ii++)
    {
        ll tmp = 35;
        cin >> x;
        for (i = 0; i < n; i++)
            for (j = 1; j <= k; j++)
            if (x - a[i]*j >= 0)
            {
             if (b.find(x-a[i]*j)!=b.end() && b[x-a[i]*j] + j <= k)
                tmp = min(tmp,b[x-a[i]*j] + j);
            }
        if (tmp == 35)
           cout << -1 << endl;
        else
            cout << tmp << endl;
    }
    return 0;
}