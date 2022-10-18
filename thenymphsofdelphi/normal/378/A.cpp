#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, m, a = 0, b = 0, c = 0;
	cin >> n >> m;
	for (int i = 1; i <= 6; i++){
		if (abs(n - i) < abs(m - i)){
			a++;
		}
		else if (abs(n - i) > abs(m - i)){
			c++;
		}
		else{
			b++;
		}
	}
	cout << a << " " << b << " " << c;
}