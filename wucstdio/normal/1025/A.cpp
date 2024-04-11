#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100005


using namespace std;



int n;
char s[N];

bool cmp ( char x  , char y ) {
	return ( int ) x < ( int ) y;
}

int main ( void ) {
	scanf("%d",&n);
	scanf("%s",s+1);
	if( n==1 ) {
		printf("Yes\n");
		return 0;
	}
	sort ( s + 1 , s + n + 1 , cmp );
	for(int i=1;i<n;i++) {
		if(s[i]==s[i+1]) {
			puts ( "Yes" );
			return 0;
		}
	}
	puts ( "No" );
	return 0;
}