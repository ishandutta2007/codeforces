#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[8001];
ll p[8001];
ll c[8001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n<=3) cout << "-1\n";
		else if(n%2==1){
			for(int i=n; i>=1 ;i-=2) cout << i << ' ';
			cout << "4 2 ";
			for(int i=6; i<=n ;i+=2) cout << i << ' ';
			cout << '\n';
		}
		else{
			for(int i=n-1; i>=1 ;i-=2) cout << i << ' ';
			cout << "4 2 ";
			for(int i=6; i<=n ;i+=2) cout << i << ' ';
			cout << '\n';
		}
	}
}