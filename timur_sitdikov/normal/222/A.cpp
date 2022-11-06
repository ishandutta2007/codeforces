#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

const int maxn=100005;
int v[maxn];

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, i, k;
	cin >> n >> k;
	k--;
	for(i=0; i<n; i++)
		cin >> v[i];
	for(i=n-2; i>=k; i--)
		if (v[i]!=v[n-1])
			break;
	if (i>=k)
	{
		cout << "-1";
		return 0;
	}
	for(; i>=0; i--)
		if (v[i]!=v[n-1])
			break;
	cout << i+1;
}