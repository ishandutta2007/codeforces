#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, c, nL=0, nR, p;
	cin >> n >> m >> c;
	int *a = new int[n];
	nR=n-1;
	while(nL<=nR) {
		cin >> p;
		if(p<=c/2) {
			if(nL==0||a[nL-1]<=p) {
				a[nL]=p;
				cout << nL+1;
				++nL;
			} else {
				int i=lower_bound(a, a+nL, p+1)-a;
				a[i]=p;
				cout << i+1;
			}
		} else {
			if(nR==n-1||a[nR+1]>=p) {
				a[nR]=p;
				cout << nR+1;
				--nR;
			} else {
				int i=upper_bound(a+nR+1, a+n, p-1)-a-1;
				a[i]=p;
				cout << i+1;
			}
		}
		cout << endl;
	}
}