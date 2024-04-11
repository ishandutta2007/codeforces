#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int n, k; 

int main() {
	cin>>n>>k; 
	if (n % k == 1) printf( "%d\n", (n-1)/k*2 ); 
	else if (n % k == 2 || k == 2) printf( "%d\n", (n-1)/k*2+1 ); 
	else printf( "%d\n", (n-1)/k*2+2 );
	for (int i = 1; i < n; ++i) printf( "%d %d\n", i, min(n,i+k) ); 
}