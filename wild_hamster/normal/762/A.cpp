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
#define N 231072
#define SUM 23423
#define MAG 100000000
#define OPEN 0
#define CLOSE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c;
vector<ll> f;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> k;
 	for (i = 1; i*i <= n; i++)
 	{
 		if (n % i == 0)
		   f.push_back(i);
 	}

	 ll sz = f.size() - 1;
 	if (f.back()*f.back() != n)
	   f.push_back(n/f.back());
	 for (i = sz-1; i >= 0; i--)
		 f.push_back(n/f[i]);
	 if (k > f.size())
		cout << -1 << endl;
	 else
		 cout << f[k-1] << endl;
    return 0;
}