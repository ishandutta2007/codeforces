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
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 228228
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,k,i,xx,yy,q,j, w, l,x;
ll a[500500];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll summ = 0;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		scanf("%I64d",&a[i]);
		summ += a[i];
	}
	ll best_ans;
	if (summ%n == 0)
	   best_ans = 0;
	else
		best_ans = 1;
	sort(a, a+n);
	ll sum = 0;
	ll max1 = a[0], min1 = a[n-1];
	for (i = 0; i < n-1; i++)
	{
	 if (i > 0)
		sum += i*(a[i] - a[i-1]);
	 if (sum > k)
		break;
	 max1 = max(max1, min(a[i] + (k-sum)/(i+1), a[i+1]));
	}
	sum = 0;
	for (i = n-1; i >= 1; i--)
	{
	 if (i < n-1)
		sum += (n-i-1)*(a[i+1] - a[i]);
	 if (sum > k)
		break;
	 min1 = min(min1, max(a[i] - (k-sum)/(n-i), a[i-1]));
	}
	//cout << min1 << " " << max1 << endl;
	cout << max(best_ans, min1 - max1) << endl;
	return 0;
}