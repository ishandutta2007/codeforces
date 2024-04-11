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
#define N 500500
#define SUM 23423
#define MAG 1048576
#define OPEN 0
#define CLOSE 1
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,h,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y;
ll a,b;
vector<pii> f;
vector<ll> g;
string s;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> a >> b >> k;
    cin >> s;
    ll st = 0;
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
    	if ((i==0||s[i-1]=='1') && s[i] == '0')
		   st = i;
    	if (s[i] == '0' &&(i == n-1 || s[i+1] == '1'))
    	{
		   f.push_back(mp(st,i));
		   ans += (i-st+1)/b;
		}
    }
    for (i = 0; i < f.size(); i++)
    {
		x = f[i].X;
		while (ans >= a && x+b-1 <= f[i].Y)
		{
			g.push_back(x+b);
			x+=b;
			ans--;
		}
    }
    cout << g.size() << endl;
    for (i = 0; i < g.size(); i++)
		printf("%d ",g[i]);
    return 0;
}