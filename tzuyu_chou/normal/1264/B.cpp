#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a[4], b[4];

void test(int x) {
	if(!a[x])
		return;
	for(int i=0; i<4; ++i)
		b[i]=a[i];
	vector<int> v{x};
	--b[x];
	while(b[0]||b[1]||b[2]||b[3]) {
		if(v.back()==0) {
			if(!b[1])
				return;
			--b[1];
			v.push_back(1);
		} else if(v.back()==3) {
			if(!b[2])
				return;
			--b[2];
			v.push_back(2);
		} else if(v.back()==1) {
			if(b[0]) {
				--b[0];
				v.push_back(0);
			} else {
				if(!b[2])
					return;
				--b[2];
				v.push_back(2);
			}
		} else {
			//2;
			if(b[3]) {
				--b[3];
				v.push_back(3);
			} else {
				if(!b[1])
					return;
				--b[1];
				v.push_back(1);
			}
		}
	}
	cout << "YES\n";
	for(int i : v)
		cout << i << " ";
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<4; ++i)
		cin >> a[i];
	for(int i=0; i<4; ++i)
		test(i);
	cout << "NO";
}