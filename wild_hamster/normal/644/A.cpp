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
ll k,i,j,n,m,s,d,cur;
ll a[1005605], fac[1005000];
vector<pii> f;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> k >> n >> m;
	if (k > n*m)
	{
		cout << -1 << endl;
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if ((i+j)%2 == 0)
			   cout << (((i*m+j)/2)*2 + 1 <= k?((i*m+j)/2)*2 + 1:0) << " ";
			else
				cout << (((i*m+j)/2)*2 + 2 <= k?((i*m+j)/2)*2 + 2:0) << " ";
		cout << endl;
	}
	return 0;
}