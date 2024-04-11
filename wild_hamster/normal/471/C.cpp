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
    cin >> n;
    i = 0;
    rez = 0;
    while (3*((i*(i+1))/2) - i <= n) i++;
    i--;
    //cout << i << endl;
    for (j = 1; j <= i; j++)
        if (j%3 == (3 - (n%3))%3) rez++;
 cout << rez << endl;
    return 0;
}