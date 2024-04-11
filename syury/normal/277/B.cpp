#include<bits/stdc++.h>

using namespace std;

int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(m == 3){
		if(n >= 5){cout << -1; return 0;}
		cout << 0 << " " << 0 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 4 << " " << 0 << endl;
		if(n == 4)cout << 2 << " " << 1 << endl;
		return 0;
	}
	int x = 0, y = 0;
	for(int i = 0; i < m; i++){
		cout << x << " " << y << endl;
		x++;
		y += i + 1;
	}
	y = 0;
	for(int i = 0; i < n - m; i++){
		cout << 100000000 - i << " " << y << endl;
		y += i + 1;
	}
	return 0;
}