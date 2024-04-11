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
ll n,m,a[15][15],i,j,k,l,x,y,z,ans;
string s;
void do_magic()
{
	i = 0; j = 0;
	x = m;
	while (x && j < n-1)
	{
		if (s[j] == 'a')
		   x--;
		if (x == 0)
		   break;
		j++;
	}
	while (j < n-1 && s[j+1] == 'b')
		  j++;
	ans = max(ans, j-i+1);
	//cout << i << " " << j << endl;
	while (j < n-1 && i < n-1)
	{
		  if (s[i] == 'b')
		  {
			 i++;
			 continue;
 		  }
 		  if (j < n-1)
			 j++;
		  while (j < n-1 && s[j+1] == 'b')
				j++;
		  i++;
		  ans = max(ans, j-i+1);
	}
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	cin >> s;
	if (m == 0)
	{
		ll ans = 1;
		ll k = 1;
		for (i = 0; i < n-1; i++)
		{
			if (s[i] == s[i+1])
			   k++;
			else
			{
				ans = max(ans,k);
				k = 1;
			}
		}
		ans = max(ans,k);
		cout << ans << endl;
		return 0;
	}
	ans = 0;
	do_magic();
	for (i = 0; i < n; i++)
		if (s[i] == 'a')
		   s[i] = 'b';
		else
			s[i] = 'a';
	do_magic();
	cout << ans << endl;
	return 0;
}