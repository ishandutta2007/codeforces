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
ll i,j,n,l,r,rez,k,m,y,z,q,k1,k2,x,a[100500],next,p;
vector <ll> f;
string s;
int main()
{
    cin >> n >> m >> x >> y >> z >> p;
    x%=4;
    y%=2;
    z%=4;
    for (i = 0; i < p; i++)
    {
         cin >> k1 >> k2;
         ll k3 = k1,k4 = k2;
         if (x == 1) k3 = k2, k4 = n - k1 +1;
         if (x == 2) k3 = n-k1+1, k4 = m - k2 +1;
         if (x == 3) k3 = m-k2+1, k4 = k1;
         k1 = k3; k2 = k4;
         if (y == 1 && x%2 == 0)
         k2 = m - k2 + 1;
         if (y == 1 && x%2 == 1)
         k2 = n - k2 + 1;
         k3 = k1; k4 = k2;
         if (x%2 == 0)
         {
         if (4-z == 1) k3 = k2, k4 = n - k1 +1;
         if (4-z == 2) k3 = n-k1+1, k4 = m - k2 +1;
         if (4-z == 3) k3 = m-k2+1, k4 = k1;
         } else
         {
         if (4-z == 1) k3 = k2, k4 = m - k1 +1;
         if (4-z == 2) k3 = m-k1+1, k4 = n - k2 +1;
         if (4-z == 3) k3 = n-k2+1, k4 = k1;      
         }
         k1 = k3; k2 = k4;
         cout << k1 << " " << k2 << endl;
    }
    return 0;
}