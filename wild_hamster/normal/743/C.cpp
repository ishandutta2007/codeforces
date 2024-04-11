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
#include <assert.h>
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
#define N 100500
#define SUM 23423
#define MAG 1048576
#define OPEN 0
#define CLOSE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,cur_x,cur_y;
ll a[100050];
string s;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	//(xy+xz+yz)*n = 2xyz
	//xzn+xyn+yzn-2xyz = 0
	//z(xn+yn-2xy) = -xyn
	//z = xyn/(2xy-xn-yn)
	cin >> n;
	if (n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << n << " " << n+1 << " " << n*(n+1) << endl;
    return 0;
}