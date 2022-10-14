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
#define MOD 1000000033
#define MOD2 (33LL+(ll)1e+17)
#define INF (1LL+2LL*(ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 118228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll p29[N],a[N],b[N],letter[N],used[N],tin[N],tout[N],up[N][18],hash[N][18],hash_back[N][18];
ll F(ll x, ll n)
{
    return x/n;
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> l >> r;
    ll to_add = (INF/n+2)*n;
    l += to_add;
    r += to_add;
    cout << F(r,n) - F(l-1,n) << endl;
    return 0;
}