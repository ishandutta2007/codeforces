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
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r;
ll a[500500];
vector <ll> s, t, ans;
vector<int> z_function (vector<ll> s) {
	int n = (int) s.size();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x);
		if (x != 0)
		   s.push_back(x);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x);
		if (x != 0)
		   t.push_back(x);
	}
	for (i = 0; i < n-1; i++)
		ans.push_back(s[i]);
	ans.push_back(2281488);
	for (i = 0; i < n-1; i++)
		ans.push_back(t[i]);
	for (i = 0; i < n-1; i++)
		ans.push_back(t[i]);
	vector <ll> z = z_function(ans);
	for (i = n-1; i < z.size(); i++)
		if (z[i] == n-1)
		{
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}