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

char S[1000]; 
char c[1000]; 
//ll a = 1000000000; 
int t; 

bool que(ll x, ll y) {
	t++; 
	assert(t <= 60); 
	printf( "? %lld %lld\n", x, y ); 
	fflush(stdout); 
	//printf( "%c\n", x % a >= y % a?'x':'y'); 
	//return x % a >= y % a; 
	scanf( "%s", c ); 
	assert(c[0] != 'e'); 
	return c[0]=='x'; 
}

int main() {
	while (1) {
		//a = rand() % 1000000000+1; 
		//a=25; 
		t = 0; 
		scanf( "%s", S ); 
		if (S[0] == 'e' || S[0] == 'm') break; 
		if (que(1,2)) {
			if (que(2,3)) printf( "! 1\n" ); 
			else printf("! 2\n" ); 
			fflush(stdout); 
			continue; 
		}
		ll p = 2; 
		while (!que(p,p*2)) p *= 2; 
		if (p > 30) {
			ll l = p, r = min(p*2,1000000000ll); 
			while (l+1 < r) {
				ll m = (l+r)/2; 
				if (que(m*2,m)) r = m; 
				else l = m; 
				//cout<<"("<<l<<','<<r<<")"<<endl;
			}
			printf( "! %lld\n", r ); 
			fflush(stdout); 
		}
		else {
			while (que(p+1,p)) p++; 
			printf( "! %lld\n", p+1 ); 
			fflush(stdout); 
		}
	}
}