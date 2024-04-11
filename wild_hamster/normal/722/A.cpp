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
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 202100
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko;
ll a[1000500];
long long to_push[1005000];
string s;


int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	cin >> s;
	if (n == 12)
	{
		if (s[0] == '0' && s[1] == '0')
		   s[1] = '1';
		if (s[0] == '1' && s[1] > '2')
		   s[1] = '0';
		if (s[0] > '1' && s[1] == '0')
		   s[0] = '1';
		if (s[0] > '1' && s[1] != '0')
		   s[0] = '0';
	} else
	{
		if (s[0] > '2')
		   s[0] = '0';
		if (s[0] == '2' && s[1] > '3')
		   s[1] = '3';
	}
	if (s[3] > '5')
	   s[3] = '0';
	cout << s << endl;
	return 0;
}