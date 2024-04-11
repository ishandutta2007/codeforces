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
ll i,j,n, previous[300], next[300], used[300];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s;
		for (j = 0; j < s.size()-1; j++)
			next[s[j]] = s[j+1], previous[s[j+1]] = s[j], used[s[j+1]] = 1;
		used[s[0]] = 1;
	}
	for (i = 'a'; i <= 'z'; i++)
	if (previous[i] == 0 && used[i])
	{
		char cur = i;
		while (cur != 0)
		{
			cout << cur;
			cur = next[cur];
		}
	}
	return 0;
}