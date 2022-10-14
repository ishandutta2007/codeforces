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
#define N 1000
#define SUM 23423
#define MAG 256
#define OPEN 0
#define CLOSE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c;
ll a[100500], b[100500];
string s;
ll to_str(string x)
{
	if (x.size() > 15 || x[0] == '0' && x.size() > 1)
	   return MOD;
	ll ans = 0;
	for (int i = 0; i < x.size(); i++)
		ans = ans*10 + x[i] - '0';
	return ans;
}
int main() {
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	cin >> n >> s;
	ll k = s.size();
	ll ans = 0;
	ll tmp = 1;
	while (k > 0)
	{
 	 for (i = 0; i < k; i++)
		 if (to_str(s.substr(i, k-i)) < n)
		 {
		 	ans = ans + to_str(s.substr(i, k-i))*tmp;
		 	k = i;
		 	break;
		 }
	  tmp *= n;
	}
	cout << ans << endl;
    return 0;
}