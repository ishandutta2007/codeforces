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
ll n,m,j,p,a[200500],c,t,l,r,h,x,y,k1,k2,k3,k4,k5,k,i,w,rez,b[100500];
map <ll,ll> f;
map <ll,ll>::iterator itr;
int main()
{
    cin >> n >> t >> c;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < c; i++)
        f[a[i]]++;
    for (i = c; i < n; i++)
    {
        itr = f.end();
        itr--;
        if (itr -> first <= t)
           rez++;
        f[a[i-c]]--;
        if (f[a[i-c]] == 0)
           f.erase(a[i-c]);
        f[a[i]]++;
    }
    itr = f.end();
        itr--;
        if (itr -> first <= t)
           rez++;
    
    cout << rez << endl;
   return 0;
}