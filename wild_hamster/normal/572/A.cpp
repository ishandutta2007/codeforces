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
ll a[100500],b[100500];
ll gt(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll S = (x1-x2)*(y1+y2)+(x2-x3)*(y2+y3)+(x3-x1)*(y3+y1);
    return S;
}
int main()
{

    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    cin >> n >> m >> k1 >> k2;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (j = 0; j < m; j++)
        cin >> b[j];
    sort(a,a+n);
    sort(b,b+m);
    if (a[k1-1] < b[m-k2])
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}