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
#define MOD 1000000009
#define MOD2 1000000009
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 1000000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 12
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz, primes[1005000], used[N+500];
string s,t;
vector<ll> f;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> k;
	for (i = 2; i <= N; i++)
		primes[i] = 1;
	for (i = 2; i <= N; i++)
		if (primes[i])
		{
			if (i == k)
			   f.push_back(i);
			for (j = i*2; j <= N; j += i)
			{
				x = j;
				y = 1;
				if (j == k)
				{
					while (x % i == 0)
					{
						x /= i;
						y *= i;
					}
					f.push_back(y);
				}
				primes[j] = 0;
			}
		}
	m = f.size();
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x);
		for (j = 0; j < m; j++)
			if (!used[j] && x % f[j] == 0)
			   used[j] = 1;
	}
	ll flag = 1;
	for (i = 0; i < m; i++)
		if (!used[i])
		   flag = 0;
	if (flag)
	   cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}