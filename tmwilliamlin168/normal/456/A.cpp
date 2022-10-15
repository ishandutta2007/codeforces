#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <unordered_map>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		if(a!=b) {
			cout << "Happy Alex";
			return 0;
		}
	}
	cout << "Poor Alex";

	return 0;
}