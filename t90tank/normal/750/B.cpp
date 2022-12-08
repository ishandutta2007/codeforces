#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
const int L = 20000; 
#define pb push_back
char st[100]; 

void Change(int &x, int t) {
	x += t; 
	x = (x%(2*L)+2*L)%(2*L); 
	if (x > L) x = 2*L-x; 
}

#define NO {puts("NO"); return 0;}
int main() {
	int n; 
	int x = 0; 
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		int t; 
		scanf( "%d%s", &t, st ); 
		if (x == 0 && st[0] != 'S') NO; 
		if (x == L && st[0] != 'N') NO; 
		if (st[0] == 'S' && x+t > L) NO;
		if (st[0] == 'N' && x-t < 0) NO; 
		if (st[0] == 'S') Change(x,t); 
		if (st[0] == 'N') Change(x,-t); 
		//cout<<x<<endl;
	}
	if (x != 0) NO; 
	puts( "YES" ); 
}