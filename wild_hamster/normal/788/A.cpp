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
#include <list>
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
#define N 10000000
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,sz,cur,sum,n,c, maxlvl,ans, A, B, timer, totH, totD;
ll a[500500], b[500500];
multiset<ll> f;
multiset<ll>::iterator itr;
ll Abs(ll x)
{
    return x>0?x:-x;
}
string s;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n-1; i++)
        b[i] = Abs(a[i] - a[i+1]);
    for (i = 0; i < n-1; i++)
    {
        if (i%2 == 0)
            x += b[i];
        else
            x -= b[i];
        f.insert(x);
    }
    ll tmp = 0;
    ll ans = 0;
    x = 0;
    for (i = 0; i < n-1; i++)
    {
        if (i%2 == 0)
        {
            itr = f.end();
            itr--;
            ans = max(ans, (*itr) - tmp);
            x += b[i];
            tmp += b[i];
        } else
        {
            itr = f.begin();
            ans = max(ans, tmp - (*itr));
            x -= b[i];
            tmp -= b[i];
        }
        itr = f.find(x);
        f.erase(itr);
    }
    cout << ans << endl;
    return 0;
}