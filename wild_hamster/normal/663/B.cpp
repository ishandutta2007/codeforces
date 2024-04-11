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
#define MOD2 (33LL+(ll)1e+17)
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-9
typedef long long ll;
typedef long double ld;
using namespace std;
ll n, k,j,i,l,x,y,z,m;
ll a[100500], p10[15];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	p10[0] = 1;
	for (i = 1; i <= 10; i++)
		p10[i] = p10[i-1]*10;
	ll tests;
	cin >> tests;
	for (int ii = 0; ii < tests; ii++)
	{
		cin >> s;
		n = 0;
		ll sz = s.size();
		for (i = 4; i < s.size(); i++)
			n = n*10 + s[i] - '0';
		m = s.size()-4;
		ll cur = 1988;
		for (i = 0; i < m; i++)
		{
			if (cur%p10[i+1] >= n%p10[i+1])
			{
			   cur /= p10[i+1];
			   cur++;
			   cur *= p10[i+1];
			   cur += n%p10[i+1];
			} else
			{
	  		  cur /= p10[i+1];
			   cur *= p10[i+1];
			   cur += n%p10[i+1];
			}
		}
		cout << cur << endl;
	}
	return 0;
}