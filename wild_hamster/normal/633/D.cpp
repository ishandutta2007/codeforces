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
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r;
ll a[1050],b[1050];
map<ll,ll> is_here;
ll Abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		is_here[a[i]]++;
		if (a[i] == 0)
		   k++;
	}
	ll ans = max(k,2);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if ((a[i] != 0 || a[j] != 0)&&i!=j)
			{
				ll sz = 0;
				k1 = a[i];
				k2 = a[j];
				b[sz++]=k1;
				b[sz++]=k2;
				is_here[k1]--;
				is_here[k2]--;
				while (1)
				{
					k2 += k1;
					k1 = k2-k1;
					if (Abs(k2) > 1000000000)
					   break;
					if (is_here.find(k2) != is_here.end() && is_here[k2] > 0)
					{
						is_here[k2]--;
						b[sz++] = k2;
					} else
					break;
				}
				ans = max(ans, sz);
				for (k = 0; k < sz; k++)
					is_here[b[k]]++;
			}
	cout << ans << endl;
	return 0;
}