#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, i, a[111], ans = 0;
	cin >> n;
	cin >> a[0];
	for (i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i - 1] == 1) {
			if (a[i] == 2){
				ans += 3;
				if(i>=2)
				if(a[i-2]==3)
				ans--;
			}
			else
				ans += 4;
		}
		else if (a[i - 1] == 2) {
			if (a[i] == 1)
				ans += 3;
			else {
				ans = -1;
				break;
			}
		}
		else{
			if (a[i] == 1)
				ans += 4;
			else {
				ans = -1;
				break;
			}
		}
	}
	if (ans < 0) {
		cout << "Infinite" << endl;
		return 0;
	}
	else
		cout << "Finite" << endl << ans << endl;
}