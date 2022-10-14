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
ll a[100500];
char s[15], t[15];
string s1,t1;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> s[0] >> s[1] >> s[3] >> s[2];
	cin >> t[0] >> t[1] >> t[3] >> t[2];
	for (i = 0; i < 4; i++)
		if (s[i] != 'X')
		   s1.push_back(s[i]);
	for (i = 0; i < 4; i++)
		if (t[i] != 'X')
		   t1.push_back(t[i]);
	//cout << s1 << " " << t1 << endl;
	ll flag = 0;
	for (i = 0; i < 3; i++)
	{
		ll tmp = 1;
		k = 0;
		for (j = i; k < 3; j = (j+1)%3, k++)
			if (s1[k] != t1[j])
			   tmp = 0;
		flag |= tmp;
	}
	if (flag == 1)
	   cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}