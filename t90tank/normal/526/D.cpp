#include <bits/stdc++.h>
using namespace std; 

const int maxn = 2000000; 

int p[maxn]; 
char s[maxn];
int n, k;  
int q[maxn]; 

int main() {
	scanf( "%d%d", &n, &k ); 
	scanf( "%s", s+1 );
	p[1] = n; 
	int j = 1;
	int t = 1; 
	for (int i = 2; i <= n; ++i) {
		if ( j > i && i + p[i-t+1] < j ) p[i] = p[i-t+1]; 
		else {	
			if ( j < i ) j = i; 
			while ( j <= n && s[j] == s[j-i+1] ) j++;
			p[i] = j - i; 
			t = i; 
		}
	}
	//for (int i = 1; i <= n; ++i) cout<<p[i]<<endl; 
	memset( q, 0, sizeof( q ) ); 
	for (int i = 1; i*k <= n; ++i) {
		bool flag = true; 
		for (int j = 1; j < k; ++j) 
			if ( p[j*i+1] < i ) {
				flag = false;  
				break; 
			}
		if ( flag ) {
		//	cout<<i*k<<' '<<i*k+min(i+1,p[i*k+1])<<endl; 
			q[i*k]++; 
			q[i*k+min(i+1,p[i*k+1]+1)]--;
		} 		
	}
	int s = 0; 
	for (int i = 1; i <= n; ++i) {
		s += q[i]; 
		if ( s > 0 ) printf( "1" ); 
		else printf( "0" ); 
	}
	printf( "\n" ); 
}