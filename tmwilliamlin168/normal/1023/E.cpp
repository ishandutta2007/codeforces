#include <bits/stdc++.h>
using namespace std;

inline bool qry(int r1, int c1, int r2, int c2) {
	if(r1>r2||c1>c2)
		return 0;
	cout << "? " << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << endl;
	string ans;
	cin >> ans;
	if(ans=="BAD")
		exit(-1);
	return ans=="YES";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	string a1, a2;
	int i=0, j=0;
	while(i+j<n-1) {
		if(qry(i+1, j, n-1, n-1)) {
			++i;
			a1+="D";
		} else {
			++j;
			a1+="R";
		}
	}
	i=n-1, j=n-1;
	while(i+j>n-1) {
		if(qry(0, 0, i, j-1)) {
			--j;
			a2+="R";
		} else {
			--i;
			a2+="D";
		}
	}
	reverse(a2.begin(), a2.end());
	cout << "! " << a1 << a2;
}