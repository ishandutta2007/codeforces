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
ll a[100500], b[100500];
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]]=1;
	}
	sort(a,a+n);
	ll flag = 0;
	for (i = 1; i <= 998; i++)
		if (b[i] + b[i+1] + b[i+2] == 3)
		   flag = 1;
	cout << (flag?"YES":"NO") << endl;
	return 0;
}