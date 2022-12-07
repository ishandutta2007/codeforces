#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = b; i >= a; i--)
 
using namespace std;
 
int n, a[105], s;
bitset<200005> B;
 
int main() {
	cin >> n;
	B[0]=1;
	rep(i,1,n) cin>>a[i], s += a[i], B = (B | (B<<a[i]));
	if(s%2==0 && !B[s/2]) {
		cout<<0<<endl;
		return 0;
	}
	rep(q,0,1000) {
		if(s&1) {
			cout << 0 << endl;
			return 0;
		}
		else {
			rep(i,1,n)
				if(a[i]%2==1) {
					cout << 1 << endl << i << endl;
					return 0;
				}
			rep(i,1,n)
				a[i]/=2;
			s/=2;
		}
	}
	
	return 0;
}