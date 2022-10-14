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
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n, m,l,r,k, q, x,y, mx, cur, INF;
ll d[1005][1005], b[100500];
string s;
ll lalkaij()
{
	cin >> d[i][j];
	j++;
	i = (j==n?i+1:i);
	j = (j==n?0:j);
	return i==n?0:lalkaij();
}

ll lalkaijk()
{
	d[i][j] = (d[i][k] < INF && d[k][j] < INF)?min(d[i][j], d[i][k] + d[k][j]):d[i][j];
	j++;
	i = (j==n?i+1:i);
	j = (j==n?0:j);
	k = (i==n?k+1:k);
	i = (i==n?0:i);
	return k==n?0:lalkaijk();
}
ll lalkaij2()
{
	q = max(q, d[i][j]);
	j++;
	i = (j==n?i+1:i);
	j = (j==n?0:j);
	return i==n?0:lalkaij2();
}
int main()
{
	//freopen("input.txt","r",stdin);
	INF = (ll)1e+9;
	cin >> n;
	lalkaij();
	i=j=k=0;
	lalkaijk();
	i=j=0;
	lalkaij2();
	cout << q << endl;
	return 0;
}