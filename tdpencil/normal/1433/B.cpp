#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 2e5;
int a[mxN+1];
int main() {
	ll T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		for(int i=0;i<N;i++){
			cin>>a[i];
		}
		int c=0;
		for(int i=0;i<N;i++){
			if(a[i]) c++;
		}
		if(c>=2) {
			int l=-1,r=0;
			for(int i=0;i<N;i++){
				if(l==-1 && a[i]) {
					l=i;
				} else {
					if(a[i]) r=i;
				}
			}
			c=0;
			for(int i=l; i <= r; i++) {
				if(!a[i]) c++;
			}
			cout << c;
		} else {
			cout << 0;
		}
		cout << '\n';
	}
}