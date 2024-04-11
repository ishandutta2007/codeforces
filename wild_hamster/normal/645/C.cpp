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
ll k,i,j,n,m,d,x,y,w,dw,l;
ll ps[100500];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> k;
	k++;
	cin >> s;
	for (i = 0; i < n; i++)
	{
		s[i] = '1' - s[i];
		m += s[i];
	}
	ps[0] = 0;
	for (i = 0; i < n; i++)
		ps[i+1] = ps[i] + s[i];
	ll ans = INF;
	for (i = 0; i < n; i++)
		if (s[i] == 1)
		{
			if (m - x < k)
			   break;
			x++;
			ll left_pos = i;
			ll l = i, r = n-1;
			while (l < r)
			{
				ll mid = (l+r-1)/2;
				ll val = ps[mid+1] - ps[i];
				if (val >= k)
				   r = mid;
				else
					l = mid+1;
			}
			ll right_pos = l;
			ll mid_pos = (left_pos+right_pos)/2;
			if (s[mid_pos] == 1)
			{
				ans = min(ans, right_pos-mid_pos);
				continue;
			}
			ll cnt = ps[mid_pos+1] - ps[left_pos];
			
			l = left_pos, r = right_pos;
			while (l < r)
			{
				ll mid = (l+r-1)/2;
				ll val = ps[mid+1] - ps[i];
				if (val >= cnt)
				   r = mid;
				else
					l = mid+1;
			}
			ans = min(ans, right_pos - l);
			
			l = left_pos, r = right_pos;
			while (l < r)
			{
				ll mid = (l+r-1)/2;
				ll val = ps[mid+1] - ps[i];
				if (val >= cnt+1)
				   r = mid;
				else
					l = mid+1;
			}
			ans = min(ans, l - left_pos);
		}
	cout << ans << endl;
	return 0;
}