#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a[4], rl=36;
	for(int i=0; i<4; ++i)
		cin >> a[i];
	cout << "36 50\n";
	for(int e=0; e<4; ++e) {
		char c1=e+'a', c2=(e+1)%4+'a';
		int ccl=a[e]-1;
		for(int i=0; i<50; ++i)
			cout << c2;
		cout << "\n";
		--rl;
		while(ccl) {
			for(int i=0; i<50; ++i) {
				if(i%2==1&&ccl) {
					cout << c1;
					--ccl;
				} else
					cout << c2;
			}
			cout << "\n";
			for(int i=0; i<50; ++i)
				cout << c2;
			cout << "\n";
			rl-=2;
		}
	}
	while(rl--) {
		for(int i=0; i<50; ++i)
			cout << 'a';
		cout << "\n";
	}
}