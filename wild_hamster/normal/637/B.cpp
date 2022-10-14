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
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-9
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,x1,y1,r,p, cur, need;
ll a[1005605], fac[1005000];
map <string, ll> f;
map <string, ll>::iterator itr;
vector<pair<ll,string> > g;
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s;
		f[s] = i+1;
	}
	for (itr = f.begin(); itr != f.end(); itr++)
	{
		g.push_back(mp((*itr).Y, (*itr).X));
	}
	sort(g.begin(), g.end());
	reverse(g.begin(), g.end());
	for (i = 0; i < g.size(); i++)
		cout << g[i].Y << endl;
	return 0;
}