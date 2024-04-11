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
ll a[300500],b[300500];
ll gcd(ll a, ll b)
{
    if (a%b == 0)
       return b;
    return gcd(b,a%b);
}
ll Abs(ll x)
{
    return x>0?x:-x;
}
bool good(ll *b, ll l, ll r)
{
    bool flag = 1;
    for (int i = l; i < r; i++)
        if (Abs(b[i]-b[i+1]) > 1)
           flag = 0;
    return flag;
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   //srand(time(0));
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    if (n <= 2)
    {
       cout << 1 << endl;
       return 0;
    }
    for (i = 0; i < n; i++)
        b[i] = i+1;
    for (i = n-1; i >= 0; i--)
        b[i] = min(b[i],n-i);
    ll cur_min = INF;
    for (i = 0; i < n; i++)
    {
        cur_min = min(cur_min+1,a[i]);
        b[i] = min(b[i],cur_min);
    }
    cur_min = INF;
    for (i = n-1; i >= 0; i--)
    {
        cur_min = min(cur_min+1,a[i]);
        b[i] = min(b[i],cur_min);
    }
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        ans = max(ans,b[i]);
        //cout << b[i] << " ";
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}