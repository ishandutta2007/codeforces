#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;

ll x1,x2,x3,n,i,j,k,x,y,m,k1,k2,k3;
pair <ll,ll> a[1005];
int main()
{
    cin >> k >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    ll flag = 1;
    for (i = 0; i < n; i++)
    {
        if (k > a[i].first)
           k += a[i].second;
        else
        flag = 0;
    }
    if (flag) cout << "YES" << endl;
       else cout << "NO" << endl;
    return 0;
}