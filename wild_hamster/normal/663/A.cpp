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
ll n, k,j,i,l,x,y,z;
ll a[100500];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	while (cin >> s)
	{
		if (s == "+")
		   a[k++] = 1, x++;
		if (s == "-")
		   a[k++] = 0, y++;
		if (s[0] >= '0' && s[0] <= '9')
		{
			for (i = 0; i < s.size(); i++)
				n = n*10+s[i]-'0';
		}
	}
	if (n*(x+1)-y >= n && x+1 <= y*n+n)
	{
		cout << "Possible" << endl;
		if (max(x+1,n) > y)
		{
			ll valx = max(max(x+1,n),y+n);
			ll valy = max(max(x+1,n),y+n)-n;
			ll dif = min(valx-x,n);
			valx -= dif;
			cout << dif;
			for (i = 0; i < k; i++)
				if (a[i])
				{
				   dif = min(valx-(x-1),n);
				   valx -= dif;
				   x--;
				   cout << " + " << dif;
	   			}
				else
				{
					dif = min(valy-(y-1),n);
					valy -= dif;
					y--;
					cout << " - " << dif;
				}
			cout << " = " << n << endl;
			return 0;
		}
		ll valx = y+n;
		ll valy = y;
		ll dif = min(valx-x,n);
		valx -= dif;
		cout << dif;
		for (i = 0; i < k; i++)
			if (a[i])
			{
			   dif = min(valx-(x-1),n);
			   valx -= dif;
			   x--;
			   cout << " + " << dif;
   			}
			else
			{
				dif = min(valy-(y-1),n);
				valy -= dif;
				y--;
				cout << " - " << dif;
			}
		cout << " = " << n << endl;
		return 0;
	}
	cout << "Impossible" << endl;
	return 0;
}