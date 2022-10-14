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
ll b[100500];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    ll rez = (ll)1e+10;
    for (i = 1; i <= 1000; i++)
    {
        ll flag = 1;
        ll sum = 0;
        for (j = 0; j < n; j++)
            if (b[j] > i && a[j] > i)
            {
             flag = 0;
             break;
            } else
            {
             if (a[j] > b[j])
                swap(a[j],b[j]);
             if (b[j] > i)
                sum += b[j];
             else
                 sum += a[j];
            }
        if (!flag) continue;
        rez = min(rez,sum*i);
    }
    cout << rez << endl;
    return 0;
}