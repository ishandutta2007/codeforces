#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	/*
	int n=15, k=5;
	for(int i=0; i<1<<n; ++i) {
		for(int j=1; j<=n; ++j) {
			bool ok1=0;
			for(int k=0; k<=n-j&&!ok1; ++k) {
				bool ok2=0;
				for(int l=0; l<=n-j&&!ok2; ++l) {
					if(k==l)
						continue;
					bool ok3=1;
					for(int m=0; m<j&&ok3; ++m)
						ok3=((i>>k+m)&1)==((i>>l+m)&1);
					ok2 = ok3;
				}
				ok1=!ok2;
			}
			if(ok1) {
				if(j==k) {
					for(int k=0; k<n; ++k)
						cout << (i>>k&1);
					cout << endl;
				}
				break;
			}
		}
	}
	//*/
	//*
	int n, k;
	cin >> n >> k;
	int p=k==1?n:(n-k)/2+1;
	for(int i=0; i<n; ++i)
		cout << (i%p>0);
	//*/
}