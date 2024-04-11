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
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,ans, curL, curR, SQ, P, Q, bad;
string t, s,s1, t1;
ll a[100500], b[100500];
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n;
 	cin >> s >> t;
 	for (i = 0; i < n; i++)
        s[i] -= '0', t[i] -= '0';
 	sort(s.begin(), s.end());
 	for (i = 0; i < n; i++)
        a[t[i]]++;
    for (i = 0; i < 10; i++)
        b[i] = a[i];
    l = n, r = 0;
    for (i = 0; i < n; i++)
    {
        for (j = s[i]; j < 10; j++)
            if (a[j])
            {
                a[j]--;
                l--;
                break;
            }
        for (j = s[i]+1; j < 10; j++)
            if (b[j])
            {
                b[j]--;
                r++;
                break;
            }
    }
    cout << l << endl << r << endl;
 	return 0;
}