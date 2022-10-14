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
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q;
ll a,b,c;
string s;
vector<ll> f1,f2,f;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> a >> b >> c;
 	cin >> n;
 	for (i = 0; i < n; i++)
 	{
 		cin >> k >> s;
 		if (s[0] == 'U')
		   f1.push_back(k);
		 else
			 f2.push_back(k);
 	}
 	sort(f1.begin(), f1.end());
 	reverse(f1.begin(), f1.end());
 	sort(f2.begin(), f2.end());
 	reverse(f2.begin(), f2.end());
 	k = 0;
 	while (!f1.empty() && a--)
 	{
 		k += f1.back();
 		f1.pop_back();
 		r++;
 	}
 	while (!f2.empty() && b--)
 	{
 		k += f2.back();
 		f2.pop_back();
 		r++;
 	}
 	for (i = 0; i < f1.size(); i++)
		f.push_back(f1[i]);
	 for (i = 0; i < f2.size(); i++)
		 f.push_back(f2[i]);
	 sort(f.begin(), f.end());
	 reverse(f.begin(), f.end());
	 while (!f.empty() && c--)
	 {
	 	k += f.back();
	 	f.pop_back();
	 	r++;
	 }
	 cout << r << " " << k << endl;
    return 0;
}