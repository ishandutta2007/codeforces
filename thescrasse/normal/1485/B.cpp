#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(NULL);
	int N,Q,K;
	cin >> N >> Q >> K;
	vector<int> v(N);
	for(int &x: v)cin >> x;
	int l,r;
	while(Q--){
		cin >> l >> r;
		cout << K + v[r-1] - v[l-1] - 2*(r - l) - 1 << "\n";
	}
	return 0;
}