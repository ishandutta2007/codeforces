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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y;
string s1,s2,s3,s,t;
ll a[100500], b[100500];
vector <ll> f;
int main()
{
	//freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
    	cin >> s;
    	if (s == "0")
    	{
    		cout << 0 << endl;
    		return 0;
    	} else
    	if (s.size() == 1)
    	{
    		if (s[0] != '1')
    		{
    			k = 1;
    			t = s;
    		}
    	}
    	if (s.size() > 1)
    	{
    		ll flag = 1;
    		for (j = 1; j < s.size(); j++)
    			if (s[j] != '0')
    				flag = 0;
    		if (s[0] != '1')
    			flag = 0;
    		if (flag == 0)
    		{
    			k = 1;
    			t = s;
    		} else
    		m += s.size() - 1;
    	}
    }
    if (k == 1)
    {
    	cout << t;
    	for (i = 0; i < m; i++)
    		cout << '0';
    } else
    {
    	cout << "1";
    	for (i = 0; i < m; i++)
    		cout << '0';
    }
	return 0;
}