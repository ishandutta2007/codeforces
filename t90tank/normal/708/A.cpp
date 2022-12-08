#include <bits/stdc++.h>

using namespace std; 

char s[200000]; 

int main() {
	scanf( "%s", s ); 
	int n = strlen( s ); 
	int b, e; 
	for (b = 0; b < n-1 && s[b] == 'a'; ++b); 
	for (e = b+1; e < n && s[e] != 'a'; ++e); 
	for (int i = b; i < e; ++i) s[i] = (s[i]-'a'+25) % 26 + 'a'; 
	printf( "%s\n", s ); 
}