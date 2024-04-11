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
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko;
ll a[1000500];
string s;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> s;
	n = s.size();
	for (i = 0; i < n-25; i++)
	{
		for (j = 'A'; j <= 'Z'; j++)
			a[j] = 0;
		k = 0;
		for (j = i; j < i+26; j++)
		{
			if (s[j] == '?')
			   k++;
			else
			if (a[s[j]] == 0)
			   k++, a[s[j]] = 1;
		}
		if (k == 26)
		{
			vector<ll> f;
			for (j = 'A'; j <= 'Z'; j++)
				if (a[j] == 0)
				   f.push_back(j);
			ll to = 0;
			for (j = i; j < i+26; j++)
				if (s[j] == '?')
				   s[j] = f[to++];
			for (j = 0; j < n; j++)
				if (s[j] == '?')
				   s[j] = 'A';
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}