#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

char s[10][10]; 
char s1[10],s2[10]; 

int main() {
	for (int i = 0; i < 4; ++i) scanf( "%s", s[i] ); 
	s1[0] = s[0][0]; 
	s1[1] = s[0][1]; 
	s1[2] = s[1][1]; 
	s1[3] = s[1][0]; 
	s2[0] = s[2][0]; 
	s2[1] = s[2][1]; 
	s2[2] = s[3][1]; 
	s2[3] = s[3][0]; 
	int p1 = 0; 
	while ( s1[p1] != 'A' ) p1 = ( p1 + 1 ) % 4; 
	int p2 = 0; 
	while ( s2[p2] != 'A' ) p2 = ( p2 + 1 ) % 4; 
	p1 = ( p1 + 1 ) % 4; 
	p2 = ( p2 + 1 ) % 4; 
	if ( s1[p1] == 'X' ) p1 = ( p1 + 1 ) % 4;
	if ( s2[p2] == 'X' ) p2 = ( p2 + 1 ) % 4;
	if ( s1[p1] != s2[p2] ) printf( "NO\n" ); 
	else printf( "YES\n" ); 
}