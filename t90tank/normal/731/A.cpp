#include <bits/stdc++.h>
using namespace std; 

string S; 

int main() {
	cin>>S; 
	int now = 0;
	int ans = 0;  
	for (int i = 0; i < S.length(); ++i) {
		int t = S[i] - 'a'; 
		ans += min((t-now+26) % 26, (now-t+26) % 26); 
		now = t; 
	}
	printf( "%d\n", ans ); 
}