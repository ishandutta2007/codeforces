#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	int i=0, i2, s;
	while(k--) {
		while(1) {
			++i;
			i2=i;
			s=0;
			while(i2>0) {
				s+=i2%10;
				i2/=10;
			}
			if(s==10)
				break;
		}
	}
	cout << i;
}