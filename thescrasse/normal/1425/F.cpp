#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int ab, abc, bc;
	vector<int> ans(n);
	cout << "? 1 2" << endl;
	cin >> ab;
	cout << "? 1 3" << endl;
	cin >> abc;
	cout << "? 2 3" << endl;
	cin >> bc;
	ans[0] = abc - bc;
	ans[2] = abc - ab;
	ans[1] = abc - ans[0] - ans[2];
	for(int i=3; i<n; ++i){
		cout << "? " << i << " " << i+1 << endl;
		int x; cin >> x;
		ans[i] = x - ans[i-1];
	}
	cout << "! ";
	for(int i:ans) cout << i << " ";
	cout << endl;
}