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

ll x1,x2,x3,n,i,j,k,x,y,m,k1,k2,k3,a[500];
string s1, s2, s3;
int main()
{
    cin >> n;
    for (i = 0; i < 12; i++)
    {
        cin >> a[i];
    }
    sort(a,a+12);
    reverse(a,a+12);
    i = 0;
    ll rez = 0;
    while (rez < n && i < 12)
    {
          rez += a[i++];
    }
    if (rez < n)
       cout << -1 << endl;
    else
        cout << i << endl;
    return 0;
}