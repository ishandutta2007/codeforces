#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int D = 10; 

int n; 
int d[20]; 
 //0 : same
 //1 : not
 //2 : 0
 //3 : 1
char op[10]; 

int main() {
	scanf( "%d", &n ); 
	memset(d, 0, sizeof(d)); 
	for (int i = 1; i <= n; ++i) {
		int x; 
		scanf( "%s%d", op, &x ); 
		if (op[0] == '&') {
			for (int j = 0; j < D; ++j) 
				if (((x >> j) & 1)==0) d[j] = 2; 
		}
		else if (op[0] == '|') {
			for (int j = 0; j < D; ++j) 
				if (((x >> j) & 1)==1) d[j] = 3; 
		}
		else if (op[0] == '^') {
			for (int j = 0; j < D; ++j) 
				if (((x >> j) & 1)==1) d[j] ^= 1; 
		}
	}
	int s1 = 0, s2 = 0; 
	for (int i = 0; i < D; ++i) {
		//cout<<d[i]<<' '; 
		if (d[i] <= 1) s1 += (1<<i); 
		if (d[i] & 1) s2 += (1<<i); 
	}
	puts( "2" ); 
	printf( "& %d\n^ %d\n", s1, s2 );
	return 0;
}