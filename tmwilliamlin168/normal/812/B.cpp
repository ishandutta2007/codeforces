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
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int* leftRoom = new int[n];
	int* rightRoom = new int[n]();
	for(int i=0; i<n; ++i)
	    leftRoom[i]=m+1;
	for(int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); ++j) {
			if(s[j]=='0')
				continue;
			if(leftRoom[n-1-i]==m+1)
				leftRoom[n-1-i]=j;
			rightRoom[n-1-i]=j;
		}
	}
	int _min=INT_MAX;
	int maxFloor=n;
	while(--maxFloor>0&&rightRoom[maxFloor]==0);
	for(int i=0; i<1<<(n-1); ++i) {
		bool atLeft=true;
		int cur=0;
		for(int j=0; j<maxFloor; ++j) {
			if(i&(1<<j)) {
				cur+=m+1;
				atLeft=!atLeft;
			} else {
				cur+=2*(atLeft?rightRoom[j]:m+1-leftRoom[j]);
			}
		}
		cur+=atLeft?rightRoom[maxFloor]:m+1-leftRoom[maxFloor];
		_min=min(cur, _min);
	}
	cout << _min+maxFloor;

	return 0;
}