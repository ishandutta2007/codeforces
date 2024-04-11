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
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-12
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,k,n1,n2,i,j,l, x,coord,p,q;
ll f[100500], t[400500];
ll Abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
   // freopen("input.txt","r",stdin);
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(Abs(x1-x2),Abs(y1-y2)) << endl;
    return 0;
}