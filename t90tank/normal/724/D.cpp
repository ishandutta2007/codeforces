#include <bits/stdc++.h>

using namespace std; 

const int maxn = 400000; 
char s[maxn];
int p0[maxn], p1[maxn]; 
int n, m; 
vector<int> ans; 

int main() {
	scanf( "%d", &m ); 
	scanf( "%s", s+1 );
	n = strlen( s+1 );  
	for (int i = 0; i < 26; ++i) {
		p0[0] = 0; 
		p1[0] = 0; 
		for (int j = 1; j <= n; ++j) {
			if ( s[j] < 'a' + i ) p0[j] = j; 
			else p0[j] = p0[j-1];  
			if ( s[j] == 'a' + i ) p1[j] = j; 
			else p1[j] = p1[j-1]; 
		}
		int pre = 0;
		int sum = 0;  
		bool flag = true; 
		while ( pre + m <= n ) 
			if ( p0[pre+m] > pre ) pre = p0[pre+m]; 
			else {
				if ( p1[pre+m] > pre ) {
					pre = p1[pre+m];
					sum++; 
				}
				else {
					flag = false; 
					break; 
				}
			}
		if ( flag ) {
			for (int j = 0; j < i; ++j) 
				for (int k = 0; k < ans[j]; ++k) printf( "%c", 'a'+j ); 
			for (int j = 0; j < sum; ++j) printf( "%c", 'a'+i ); 
			printf( "\n" ); 
			break; 
		}
		sum = 0; 
		for (int j = 1; j <= n; ++j) sum += (i+'a'==s[j]); 
		ans.push_back( sum ); 
	}
}