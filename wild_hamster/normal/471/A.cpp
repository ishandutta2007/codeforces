 #include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll rez,l,r,n,m,k,j,p,k1,k2,i;
ll a[140000];
vector <ll> primes, total;
ll Abs(ll x)
{
 if (x < 0) return -x;
    return x;
}
int main()
{
    for (i = 0; i < 6; i++)
        cin >> a[i];
    sort(a,a+6);
    if ((a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[4] == a[5]) ||
    (a[3] == a[4] && a[4] == a[5] && a[2] == a[3] && a[0] == a[1]))
         cout << "Elephant" << endl; else
    if ((a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[4] != a[5]) ||
    (a[3] == a[4] && a[4] == a[5] && a[2] == a[3] && a[0] != a[1]) ||
    (a[3] == a[4] && a[1] == a[2] && a[2] == a[3] && a[0] != a[5]))
         cout << "Bear" << endl;
    else
        cout << "Alien" << endl;
    return 0;
}