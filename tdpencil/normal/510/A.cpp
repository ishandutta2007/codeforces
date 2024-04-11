#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	for(int i=1; i <= n; i++) {
		if(i&1) {
			for(int j=0; j < k; j++)
				cout << "#";
		} else {
			if(i%4==2) {
				for(int j=0; j < k-1; j++)
					cout << ".";
				cout << "#";
			} else {
				cout << "#";
				for(int j=0; j < k-1; j++)
					cout << ".";
			}
		}

		cout << "\n";
	}
}