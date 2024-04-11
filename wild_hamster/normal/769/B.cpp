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
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,nn, hs, ml,cnt;
string s,t,s1;
ll a[300500];
vector<pii> f, an;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
        if (i)
            f.push_back(mp(a[i], i));
    }
    if (a[0] == 0 || tot < n-1)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    int cur = 0;
    cout << n-1 << endl;
    x = a[0];
    while (cur < n-1 && x > 0)
    {
        x--;
        cout << 1 << " " << f[cur].Y+1 << endl;
        cur++;
    }
    for (i = 0; i < n-1; i++)
    {
        x = f[i].X;
        while (cur < n-1 && x > 0)
        {
            x--;
            cout << f[i].Y+1 << " " << f[cur].Y+1 << endl;
            cur++;
        }
    }
    return 0;
}