#include<bits/stdc++.h>
using namespace std;
#define s size()

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> first(N);
	vector<int> second(M);
	
	vector<int> firstevens;
	vector<int> secondevens;
	
	vector<int> firstodds;
	vector<int> secondodds;
	
	for(auto &v: first) cin >> v;
	for(auto &v: second) cin >> v;
	
	int ans =0;
	
	for(auto &v: first) {
		if(v & 1) firstodds.push_back(v);
		else firstevens.push_back(v);
	}
	for(auto &v: second) {
		if(v & 1) secondodds.push_back(v);
		else secondevens.push_back(v);
	}
	
	ans += min(firstodds.s, secondevens.s);
	
	ans += min(firstevens.s, secondodds.s);
	
	cout << ans << '\n';
}