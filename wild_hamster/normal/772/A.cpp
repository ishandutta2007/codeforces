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
#define SQ 317
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,sz,cur,sum,n,c, maxlvl,q, start_pnt;
string s,t;
ll a[100500], b[100500];
vector<ll> f;
double p;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
 	//cin >> s;
    cin >> n >> p;
    for (i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        x += a[i];
    }
    if (x <= p)
    {
        cout << -1 << endl;
        return 0;
    }
    long double l = 0, r = 1e+12;
    for (int ii = 0; ii <= 100; ii++)
    {
        long double mid = (l+r)/2;
        long double sum = 0;
        for (i = 0; i < n; i++)
        {
            long double y = mid*a[i] - b[i];
            if (y < 0)
                y = 0;
            sum += y;
        }
        if (sum <= mid*p)
            l = mid;
        else
            r = mid;
    }
    printf("%.8f\n",(double)l);
    return 0;
}