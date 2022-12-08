#include <bits/stdc++.h>
using namespace std; 

char s[200000]; 
//Bulbasaur
int b[256];

int main() {
	scanf( "%s", s ); 
	int len = strlen( s ); 
	for (int i = 0; i < len; ++i) 
		b[s[i]]++; 
	printf( "%d\n", min(min(min(min(min(min(b['B'],b['u']/2),b['l']),b['b']),b['a']/2),b['s']),b['r']) ); 
}