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

ll n,i,j,x,y,a[100500],m,k1,k2,rez;

int main()
{
    cin >> n >> x;
    for (i = 1; i < n; i++)
        cin >> a[i];
    ll l = 1;
    while (l != n && l!=x)
    {
          l += a[l];
    }
    if (l == x)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}