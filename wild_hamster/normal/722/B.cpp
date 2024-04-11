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
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko;
ll a[1000500];
string s;
int f(string x)
{
	int k = 0;
	for (int i = 0; i < x.size(); i++)
		if (x[i] == 'a' || x[i] == 'o' || x[i] == 'i' || x[i] == 'u' || x[i] == 'e' || x[i] == 'y')
		   k++;
	return k;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	getline(cin, s);
	for (i = 0; i < n; i++)
	{
		getline(cin, s);
		if (f(s) != a[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}