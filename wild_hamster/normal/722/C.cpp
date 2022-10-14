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
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 202100
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko;
ll a[1000500], b[1005000];
string s;
multiset<ll> f,g;
multiset<ll>::iterator itr;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i+1] = b[i] + a[i];
	}
	f.insert(-1);
	f.insert(n);
	g.insert(b[n]);
	for (i = 0; i < n; i++)
	{
		cin >> x;
		x--;
		itr = f.upper_bound(x);
		r = *itr;
		itr--;
		l = *itr;
		f.insert(x);
		itr = g.find(b[r] - b[l+1]);
		g.erase(itr);
		g.insert(b[x] - b[l+1]);
		g.insert(b[r] - b[x+1]);
		itr = g.end();
		itr--;
		cout << *itr << endl;
	}
	return 0;
}