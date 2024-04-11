#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,b[100500];
pair <ll,ll> a[100500];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a,a+n);
    k = 0;
    for (i = 0; i < n; i++)
        if (a[i].second >= k)
           k = a[i].second;
        else
            k = a[i].first;
    cout << k << endl;
   return 0;
}