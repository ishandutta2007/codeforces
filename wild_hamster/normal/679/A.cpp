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
#define N 20000
#define mx 112
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,i,j,k,kk,l,r,x,y,z,ans,flag;
ll dp[1005][1005], a[100505], b[105005];
string s;
ll p[15] = {	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	for (i = 0; i < 15; i++)
	{
		cout << p[i] << endl;
		fflush(stdout);
		cin >> s;
		if (s == "yes")
		{
			if (p[i]*p[i] <= 100)
			{
				cout << p[i]*p[i] << endl;
				fflush(stdout);
				cin >> s;
				if (s == "yes")
				{
					cout << "composite" << endl;
					fflush(stdout);
					return 0;
				}
			}
			for (j = i+1; j < 15; j++)
			{
				if (p[i]*p[j] > 100)
				   break;
				cout << p[i]*p[j] << endl;
				fflush(stdout);
				cin >> s;
				if (s == "yes")
				{
					cout << "composite" << endl;
					fflush(stdout);
					return 0;
				}
			}
			cout << "prime" << endl;
			fflush(stdout);
			return 0;
		}
	}
	cout << "prime" << endl;
	fflush(stdout);
	return 0;
}