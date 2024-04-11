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
string s1, s2, s3;
int main()
{
    cin >> n;
    cin >> k;
    ll max1 = k, min1 = k;
    ll rez = 0;
    for (i = 0; i < n-1; i++)
    {
        cin >> x;
        if (x < min1)
           min1 = x, rez++;
        if (x > max1)
           max1 = x, rez++;
    }
    cout << rez << endl;
    return 0;
}