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
		int n,k;
		cin >> k >> n;
		int l=0,r=2*n;
		while(l!=r){
			//cout << l << ' ' << r << '\n';
			int m=l+(r-l)/2;
			if(m-m/k<n) l=m+1;
			else r=m;
		}
		cout << l << '\n';
	}
}