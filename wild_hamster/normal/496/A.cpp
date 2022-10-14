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
ll i,dp[5],n,a[105],rez;
string s1,s2;

int main()
{
    cin >> n;
    rez = 0;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n-1; i++)
        rez = max(rez,a[i+1]-a[i]);
    ll tmp = (ll)1e+18;
    for (i = 0; i < n-2; i++)
        tmp = min(tmp,a[i+2]-a[i]);
    cout << max(rez,tmp) << endl;
    return 0;
}