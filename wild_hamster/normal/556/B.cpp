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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll dp[100][30],i,j,n,k[5],k1,k2,m,y;
string s;
ll a[5005],b[5005];
int main()
{
    cin >> n;
    ll flag1 = 0;
    ll flag2 = 0;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        if (i%2)
           b[i] = (-a[i]+i+n)%n;
        else
            b[i] = (a[i]-i+n)%n;
    for (i = 0; i < n-1; i++)
        if (b[i] != b[i+1])
           flag1 = 1;
    for (i = 0; i < n; i++)
        if (i%2==0)
           b[i] = (-a[i]+i+n)%n;
        else
            b[i] = (a[i]-i+n)%n;
    for (i = 0; i < n-1; i++)
        if (b[i] != b[i+1])
           flag2 = 1;
    if (flag1 && flag2)
       cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}