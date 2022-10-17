#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int x = n-3;
		x/=3;
		int y = x;
		if(n%3==0){
			y++;
		}
		else if(n%3==1){
			y++;
		}
		else{
			y+=2;
		}
		cout << y << " " << n-x-y << " " << x << "\n";
	}
	return 0;
}