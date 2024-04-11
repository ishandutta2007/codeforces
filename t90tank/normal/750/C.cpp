#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;

int n; 
int s[300000]; 
int d[300000]; 

int main() {
	int maxd = 0x3f3f3f3f; 
	s[0] = 0; 
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		int c; 
		scanf( "%d %d", &c, &d[i] ); 
		if (d[i] == 2) 
			maxd = min(maxd, 1899-s[i-1]); 
		s[i] = s[i-1] + c; 
	}
	if (maxd == 0x3f3f3f3f) puts( "Infinity" ); 
	else {
		for (int i = 1; i <= n; ++i) 
			if (!((s[i-1]+maxd >= 1900)==(d[i]==1))) {
				puts( "Impossible" ); 
				return 0; 
			}
		cout<<maxd+s[n]<<endl; 
	}
}