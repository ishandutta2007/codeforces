#include <iostream>
//#include <cmath>
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
#define MOD3 10000000000000061LL
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 500000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 12
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,sz, q, total, ans, k1,k2;
ll a[200500];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x > y)
		   k1++;
		if (x < y)
		   k2++;
	}
	if (k1 < k2)
	   cout << "Chris" << endl;
	else
	if (k1 > k2)
	   cout << "Mishka" << endl;
	else
		cout << "Friendship is magic!^^" << endl;
	return 0;
}