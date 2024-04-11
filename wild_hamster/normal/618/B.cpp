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
ll a[65][65], b[65];
vector <ll> f;
int main()
{
	//freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    	for (j = 0; j < n; j++)
    		cin >> a[i][j];
	for (i = 1; i < n; i++)
	{		
		for (j = 0; j < n; j++)
		{
			ll flag = 1;
			ll sum = 0;
			for (k = 0; k < n; k++)
			{
				if (a[j][k] != 0 && a[j][k] != i)
					flag = 0;
				sum += a[j][k];
			}
			if (sum == 0)
				flag = 0;
					sum = 0;
			for (k = 0; k < n; k++)
			{
				sum += a[k][j];
				if (a[k][j] != 0 && a[k][j] != i)
					flag = 0;
			}
			if (sum == 0)
				flag = 0;
			if (flag)
			{
				b[j] = i;
				for (k = 0; k < n; k++)
					a[j][k] = a[k][j] = 0;
			}
		}
		
	}
	for (i = 0; i < n; i++)
		if (b[i] == 0)
			cout << n << " ";
		else
			cout << b[i] << " ";
	return 0;
}