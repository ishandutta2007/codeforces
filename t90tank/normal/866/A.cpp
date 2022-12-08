#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int a; 

int main() {
	cin>>a; 
	if (a == 1) {
		printf( "1 1\n1\n" ); 
		return 0; 
	}
	printf( "%d 2\n", (a-1)*2 ); 
	printf( "1 2\n" );
	return 0;
}