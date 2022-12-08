#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std; 

string s[200000]; 
int n; 

bool check( string s ) 
{
	if ( s[0] != '1' ) return false; 
	int len = s.length();
	for (int i = 1; i < len; ++i) 
		if ( s[i] != '0' ) return false; 
	return true; 
}

string Outer; 
int l; 

int main() 
{
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) cin >> s[i]; 
	for (int i = 1; i <= n; ++i) 
		while ( s[i].length() > 1 && s[i][0] == '0' ) 
			s[i].erase( 0, 1 ); 
	bool flag = false; 
	l = 0; 
	Outer = "1"; 
	for (int i = 1; i <= n; ++i) 
		if ( s[i].length() == 1 && s[i][0] == '0' ) 
		{ flag = true; break; }
		else if ( check( s[i] ) ) l += s[i].length()-1; 
		else Outer = s[i]; 
	if ( flag ) printf( "0\n" ); 
	else {
		cout<<Outer; 
		for (int i = 1; i <= l; ++i) printf( "0" ); 
		printf( "\n" ); 
	}
}