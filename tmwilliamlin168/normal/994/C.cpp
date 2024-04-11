#include <bits/stdc++.h>
using namespace std;

int a[16];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<16; ++i)
		cin >> a[i];
	int mnx1=6969, mny1=6969, mxx1=-6969, mxy1=-6969;
	for(int i=0; i<4; ++i) {
		mnx1=min(a[2*i], mnx1);
		mny1=min(a[1+2*i], mny1);
		mxx1=max(a[2*i], mxx1);
		mxy1=max(a[1+2*i], mxy1);
	}
	for(int i=8; i<16; i+=2)
		a[i]+=a[i+1], a[i+1]=a[i]-2*a[i+1];
	int mnx2=6969, mny2=6969, mxx2=-6969, mxy2=-6969;
	for(int i=0; i<4; ++i) {
		mnx2=min(a[8+2*i], mnx2);
		mny2=min(a[9+2*i], mny2);
		mxx2=max(a[8+2*i], mxx2);
		mxy2=max(a[9+2*i], mxy2);
	}
	for(int x=mnx1; x<=mxx1; ++x) {
		for(int y=mny1; y<=mxy1; ++y) {
			if(x+y>=mnx2&&x+y<=mxx2&&x-y>=mny2&&x-y<=mxy2) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}