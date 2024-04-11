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

	int* leftBigger = new int[n];
	stack<int> theStack;
	for(int i=0; i<n; ++i) {
		while(!theStack.empty()&&ar[theStack.top()]>=ar[i]) {
			theStack.pop();
		}
		if(theStack.empty())
			leftBigger[i]=i;
		else
			leftBigger[i]=i-theStack.top()-1;
		theStack.push(i);
	}

	int* rightBigger = new int[n];
	theStack=stack<int>();
	for(int i=n-1; i>=0; --i) {
		while(!theStack.empty()&&ar[theStack.top()]>=ar[i]) {
			theStack.pop();
		}
		if(theStack.empty())
			rightBigger[i]=n-i-1;
		else
			rightBigger[i]=theStack.top()-i-1;
		theStack.push(i);
	}

	int* maxStrength = new int[n+1];
	for(int i=1; i<=n; ++i)
		maxStrength[i]=0;
	for(int i=0; i<n; ++i) {
		int groupSize=leftBigger[i]+rightBigger[i]+1;
		maxStrength[groupSize]=max(ar[i], maxStrength[groupSize]);
	}
	for(int i=n-1; i>0; --i)
		maxStrength[i]=max(maxStrength[i], maxStrength[i+1]);
	for(int i=1; i<=n; ++i)
		cout << maxStrength[i] << ' ';
	return 0;
}