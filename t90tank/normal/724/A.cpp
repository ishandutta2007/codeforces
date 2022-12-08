#include <bits/stdc++.h>
using namespace std; 

const string s = "motuwethfrsasu"; 

int main() {
	string s1, s2; 
	cin>>s1>>s2; 
	int a, b; 
	for (int i = 0; i < s.length(); i+=2) 
		if ( s[i] == s1[0] && s[i+1] == s1[1] ) a = i / 2;
	for (int i = 0; i < s.length(); i+=2) 
		if ( s[i] == s2[0] && s[i+1] == s2[1] ) b = i / 2;
	int t = ( b - a + 7 ) % 7; 
	if ( t == 0 || t == 2 || t == 3 ) printf( "YES\n" ); 
	else printf( "NO\n" ); 
}