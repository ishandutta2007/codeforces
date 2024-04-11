#include <iostream>
//#include <cmath>
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
#define N 500000
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,m,x,y;
ll a[100500];
string s;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> s;
	i = 0;
	n = s.size();
	while (i < n)
	{
		if (s[i] != 'a')
		   break;
		i++;
	}
	if (i == n)
	{
		s[n-1] = 'z';
		cout << s << endl;
		return 0;
	}
	j = i;
	while (j < n && s[j] != 'a')
		  j++;
	for (k = i; k < j; k++)
		s[k]--;
	cout << s << endl;
	return 0;
}