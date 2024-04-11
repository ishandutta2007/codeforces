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
double a[100500], b[100500];
vector<ll> f;
double p;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
 	//cin >> s;
 	cin >> n;
 	for (i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    double ans = 1e+12;
    for (i = 0; i < n; i++)
    {
        double x1 = a[i], y1 = b[i], x2 = a[(i+1)%n], y2 = b[(i+1)%n];
        double x3 = a[(i+2)%n], y3 = b[(i+2)%n];
        double S = (x1+x2)*(y1-y2)+(x2+x3)*(y2-y3)+(x3+x1)*(y3-y1);
        if (S < 0)
            S = -S;

        double A = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        ans = min(ans, S/A);
        A = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
        ans = min(ans, S/A);
        A = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
        ans = min(ans, S/A);
    }
    printf("%.8f\n", ans/2);
    return 0;
}