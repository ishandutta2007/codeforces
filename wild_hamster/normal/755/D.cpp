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
#define MAG 166
#define OPEN 0
#define CLOSE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c;
ll primes[1005000];
ll t[5000500];
set<ll> f;
string s;

void modify(int p, int value) {  // set value at position p
  for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(int l, int r) {  // sum on interval [l, r)
if (l > r)
   return 0;
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	//print();
	cin >> n >> k;
	if (2*k > n)
	    k = n-k;
	x = 0;
	ll ans = 1;
	for (i = 0; i < n; i++)
	{
		ll nxt = x+k;
		if (nxt < n)
		{
			ans += query(x+1, nxt);
			modify(x,1);
			modify(x+k,1);
		} else
		{
			nxt -= n;
			ans += query(x+1, n);
			ans += query(0, nxt);
			modify(x,1);
			modify(nxt,1);
		}
		x = nxt;
		ans++;
		printf("%I64d ", ans);
	}
    return 0;
}