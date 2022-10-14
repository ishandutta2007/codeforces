#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, x1, y1, x2, y2;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 || y1 == y2){
			cout << abs(x1-x2) + abs(y1-y2) << '\n';
		}
		else cout << abs(x1-x2) + abs(y1-y2) + 2 << '\n';
	}
}