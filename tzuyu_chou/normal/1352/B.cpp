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
		int k;cin >> k;
		if(n%2==k%2 && n>=k){
			cout << "YES\n";
			for(int i=1; i<k ;i++) cout << 1 << ' ';
			cout << n-k+1 << '\n';
			continue;
		}
		if(n%2==0 && n>=2*k){
			cout << "YES\n";
			for(int i=1; i<k ;i++) cout << 2 << ' ';
			cout << n-k*2+2 << '\n';
			continue;
		}
		cout << "NO\n";
	}
}