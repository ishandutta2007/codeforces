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
ll lalka(ll a, ll b)
{
 ll i, rez = 0;
 for (i = 1; i*i <= a; i++)
 {
     if (i*i == a && i > b)
        rez++;
     else
     if (a % i == 0)
     {
      if (i > b) rez++;
      if (a/i > b) rez++;
     }
 }
 return rez;
}
ll n,i,j,x,y,rez[100500],m;

int main()
{
    cin >> n >> m;
    if (n == m)
       cout << "infinity" << endl;
    else
    if (n <= m*2)
       cout << 0 << endl;
    else
        cout << lalka(n-m,m) << endl;
    return 0;
}