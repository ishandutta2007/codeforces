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
#define MOD 1000000009
#define MOD2 1000000009
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 1000000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 12
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz, a[5005], used[N+500], dp[3][505][505];
string s,t;
vector<ll> f;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> k;
	dp[0][0][0] = 1;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (i = 0; i < n; i++)
	{
		ll cur = i%2, nt = (i+1)%2;
		for (j = 0; j <= k; j++)
			for (l = 0; l <= k; l++)
				dp[nt][j][l] = 0;
		for (j = 0; j <= k; j++)
			for (l = 0; l <= k; l++)
				if (dp[cur][j][l])
				{
					dp[nt][j][l] = 1;
					if (j + a[i] <= k)
					   dp[nt][j+a[i]][l] = 1;
					if (l + a[i] <= k)
					   dp[nt][j][l+a[i]] = 1;
				}
	}
	for (i = 0; i <= k; i++)
		if (dp[n%2][i][k-i])
		   f.push_back(i);
	cout << f.size() << endl;
	for (i = 0; i < f.size(); i++)
		cout << f[i] << " ";
	cout << endl;
	return 0;
}