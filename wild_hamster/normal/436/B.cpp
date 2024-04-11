#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
#include <complex>
//#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100500
#define eps 1e-9
#define PI 3.14159265358979323846

ll a[2500],bu[100500];
ll i,j,k,n,k1,jk1,j2,k2,k3,y,m;
char x;
int main()
{
cin >> n >> m >> k;
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    {
        cin >> x;
        if (x == 'R' && j + i < m) a[j+i]++;
        if (x == 'L' && j - i >= 0) a[j-i]++;
        if (x == 'U' && i % 2 == 0) a[j]++;
    }
for (i = 0; i < m; i++)
    cout << a[i] << " ";
return 0;
}