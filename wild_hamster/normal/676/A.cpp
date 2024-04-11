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
#define INF (1LL+(ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 100500
#define mx 112
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,a[100500],i,j,k,l,x,y,z;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	ll ans = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		if (x == n || x == 1)
		{
		   ans = max(ans, i-1);
		   ans = max(ans, n-i);
		}
	}
	cout << ans << endl;
	return 0;
}