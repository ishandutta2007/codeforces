#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,i,j,d,x,y,m,l,r,sum,a[1005][1005];
double k,rez,tmp;
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        a[1][i] = 1;
        a[i][1] = 1;
    }
    for (i = 2; i <= n; i++)
        for (j = 2; j <= n; j++)
            a[i][j] = a[i-1][j] + a[i][j-1];
    cout << a[n][n] << endl;
    return 0;
}