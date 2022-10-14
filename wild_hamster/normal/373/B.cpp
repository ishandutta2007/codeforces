#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
vector <ll> divisors,ans;
ll a[100500],b[25];
ll find(ll x)
{
    ll y = x;
    ll k = 0;
    while (y)
    {
        y /= 10;
        k++;
    }
    return k*(x+1) - b[k-1];
}
int main()
{
    //freopen("input.txt","r",stdin);
    ll w,m,k;
    x = 1;
    b[0] = 1;
    for (i = 1; i <= 18; i++)
    {
        x *= 10;
        b[i] = b[i-1] + x;
    }
    cin >> w >> m >> k;
    ll l = m-1, r = (ll)1e+17;
    //cout << find(m-1) << endl;
    while (l < r)
    {
        ll mid = (l+r+1)/2;
        ll cur_ans = find(mid) - find(m-1);
        //cout << mid << " " << cur_ans << endl;
        if (cur_ans <= w/k)
           l = mid;
        else
            r = mid-1;
    }
    cout << l-m+1 << endl;
    return 0;
}