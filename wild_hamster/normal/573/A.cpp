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
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,x,y,y1,x2,y2,x3,y3,h,z,l1,l2,l3;
string s1,s2,s3,s,t;
ll a[300500];
ll gcd(ll a, ll b)
{
    if (a%b == 0)
       return b;
    return gcd(b,a%b);
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        while (a[i] %2 == 0)
              a[i] /= 2;
        while (a[i] %3 == 0)
              a[i] /= 3;
    }
    ll flag = 1;
    for (i = 0; i < n-1; i++)
        if (a[i] != a[i+1])
           flag = 0;
    if (flag)
       cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}