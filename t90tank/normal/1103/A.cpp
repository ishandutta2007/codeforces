#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

char s[2000]; 

int main() {
	scanf( "%s", s ); 
	int x = 0, y = 0; 
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i]=='0') printf( "%d 1\n", ((x++) & 1)*2+1); 
		else printf( "%d 3\n", ((y++) % 4+1)); 
	}
}