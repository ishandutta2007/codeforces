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
    cin >> n >> x >> y;
    for (i = 1; i <= n; i++)
        if (i - 1 >= x && n-i <= y)
           m++;
    cout << m << endl;
    return 0;
}