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
#define N 500000
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r, a[500050];
string s[10050];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	k = -1; m = -1;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
		if (s[i][0] == 'O' && s[i][1] == 'O')
		   k = i, m = 0;
		if (s[i][3] == 'O' && s[i][4] == 'O')
		   k = i, m = 1;
	}
	if (k == -1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	s[k][m*3] = s[k][m*3+1] = '+';
	for (i = 0; i < n; i++)
		cout << s[i] << endl;
	return 0;
}