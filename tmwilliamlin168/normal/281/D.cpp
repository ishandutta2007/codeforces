#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int* ar = new int[n];
	for(int i=0; i<n; ++i)
		cin >> ar[i];
	int _max=0;

	stack<int> thestack;
	for(int i=0; i<n; ++i) {
		while(!thestack.empty()&&ar[i]>=thestack.top()) {
			int a=thestack.top();
			thestack.pop();
			_max=max(a^ar[i], _max);
		}
		thestack.push(ar[i]);
	}
	thestack=stack<int>();
	for(int i=n-1; i>=0; --i) {
		while(!thestack.empty()&&ar[i]>=thestack.top()) {
			int a=thestack.top();
			thestack.pop();
			_max=max(a^ar[i], _max);
		}
		thestack.push(ar[i]);
	}
	cout << _max;

	return 0;
}