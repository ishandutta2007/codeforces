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
#define INF (1LL+(ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 100500
#define mx 112
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,a[105000],b[105],d[105],pre[100500][105],i,j,k,l,x,y,z,ans;
string s;
ll primes[3000005];
vector<ll> prs;
ll to_int(string s)
{
	ll x = 0;
	ll zn = 1;
	if (s[x] == '-')
	   zn = -1, x++;
	ll val = 0;
	for (int i = x; i < s.size(); i++)
	{
		val = val*10+s[i]-'0';
	}
	return val*zn;
}
int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	for (i = 2; i <= 3000000; i++)
		primes[i] = 1;
	for (i = 2; i <= 3000000; i++)
	if (primes[i])
	{
		prs.push_back(i);
		for (j = i*2; j <= 3000000; j+= i)
			primes[j] = 0;
	}
	ll sz = prs.size();
	//cout << sz << endl;
	srand(time(0));

	for (i = 0; i < 100; i++)
		b[i] = prs[rand()%sz];
	cin >> n >> k;
	for (i = 0; i < 100; i++)
	{
		pre[0][i] = 1;
		for (j = 1; j <= 100000; j++)
			pre[j][i] = (pre[j-1][i]*k)%b[i];

	}
	for (i = 0; i <= n; i++)
	{
		cin >> s;
		if (s == "0" && i == 0 && k == 0)
		{
		   cout << "Yes" << endl;
		   return 0;
		}
		if (s != "0" && s != "?" && i == 0 && k == 0)
		{
		   cout << "No" << endl;
		   return 0;
		}
		if (s == "?" && k != 0)
		{
			if (n % 2 == 0)
			{
				cout << "No" << endl;
			} else
			  cout << "Yes" << endl;
			return 0;
		} else
		if (s != "?")
		   m++;
		ll val = to_int(s);
		for (j = 0; j < 100; j++)
		{
			d[j] += val*pre[i][j];
			d[j] %= b[j];
			if (d[j] < 0)
			   d[j] += b[j];
		}
	}
	if (k == 0)
	{
		 if (m%2 == 1)
		 	cout << "Yes" << endl;
			else
			cout << "No" << endl;
		return 0;
	}
	ll flag = 1;
	for (j = 0; j < 100; j++)
		if (d[j] != 0)
		   flag = 0;
	cout << (flag?"Yes":"No") << endl;
	return 0;
}