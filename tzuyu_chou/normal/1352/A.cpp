#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
void upd(int& x,int y){
	x=max(x,y);
}
vector<int>v;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;cin >> n;
		int z=0;
		v.clear();
		while(n!=0){
			while(n%10==0) n/=10,z++;
			v.push_back(n%10);
			n-=n%10;
			for(int i=0; i<z ;i++) v.back()*=10;
		}
		cout << v.size() << '\n';
		for(auto cur:v) cout << cur << ' ';
		cout << '\n';
	}
}