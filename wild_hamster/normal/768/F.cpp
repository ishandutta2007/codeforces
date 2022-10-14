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
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define eps 1e-7
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c,ans, curL, curR, SQ, P, Q;
ll F, W, H;
ll fac[300500], inv[300500];
ll binpow(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = (tmp*tmp)%MOD;
    if (y%2 == 0)
        return tmp;
    return (x*tmp)%MOD;
}
ll C(ll n, ll m)
{
    if (m < 0 || n < 0 || m > n)
        return 0;
    ll tmp = fac[n]*inv[m]%MOD;
    return (tmp*inv[n-m])%MOD;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	fac[0] = inv[0] = 1;
 	for (i = 1; i <= 300000; i++)
    {
        fac[i] = (fac[i-1]*i)%MOD;
        inv[i] = binpow(fac[i], MOD-2);
    }
    cin >> F >> W >> H;
    H++;
    if (W == 0 || F == 0)
    {
        if (W == 0)
        {
            cout << 1 << endl;
        } else
        if (F == 0)
        {
            if (W >= H)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        return 0;
    }
    for (i = 1; i <= F; i++)
    {
        if (i-1 >= 0)//food i, wine i-1
        {
            Q = (Q+C(F-1, i-1)*C(W-1, i-2))%MOD;
            P = (P+C(F-1, i-1)*C(W-1-(H-1)*(i-1), i-2))%MOD;
        }
        Q = (Q+2*C(F-1, i-1)*C(W-1, i-1))%MOD;
        P = (P+2*C(F-1, i-1)*C(W-1-(H-1)*i, i-1))%MOD;
        Q = (Q+C(F-1, i-1)*C(W-1, i))%MOD;
        P = (P+C(F-1, i-1)*C(W-1-(H-1)*(i+1), i))%MOD;
    }
    cout << P*binpow(Q,MOD-2)%MOD << endl;
    return 0;
}