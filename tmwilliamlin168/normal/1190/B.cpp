#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//n=1
	//3 same piles -> automatic loss
	//2 pairs of same piles -> automatic loss
	//x x+1 x+1 -> loss
	//0 0 -> loss
	//otherwise, state before losing is 0, 1, 2, ...
	int n;
	cin >> n;
	map<int, int> c;
	ll s=0;
	for(int i=0; i<n; ++i) {
		int ai;
		cin >> ai;
		c[ai]++;
		s+=ai;
	}
	bool w=1;
	int e=0;
	for(auto a : c) {
		e+=a.second-1;
		//if(a.second>1&&c[a.first-1])
		if(a.second>1&&c.find(a.first-1)!=c.end())
			w=0;
	}
	if(c[0]>=2)
		w=0;
	if(e>1)
		w=0;
	if((s-(ll)n*(n-1)/2)&1^1)
		w=0;
	cout << (w?"sjfnb":"cslnb");
}