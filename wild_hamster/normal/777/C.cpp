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
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define eps 1e-7
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,ans, curL, curR, SQ, P, Q, bad, N;
ll b[100500], a[100500], t[400500], an[100500];

int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> m;
 	for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> b[i*m+j];
    N = m*n;
    for (j = 0; j < m; j++)
    {
        k = 1;
        for (i = 0; i < n; i++)
        {
            a[i*m+j] = k;
            if (i+1 < n && b[(i+1)*m+j] >= b[i*m+j])
                k++;
            else
                k = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            an[i] = max(an[i], a[i*m+j]);
    }
    cin >> k;
    for (i = 0; i < k; i++)
    {
        cin >> l >> r;
        l--;r--;
        cout << (an[r]>=r-l+1?"Yes":"No") << endl;
    }
 	return 0;
}