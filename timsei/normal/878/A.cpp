#include <cstdio>
#include <iostream> 
using namespace std;

const int N = 5e5 + 5;

int a[N] , n , bit[15][3];

char s[N][5];

int main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%s" , s[i]); scanf("%d" , &a[i]);
	}
	for(int i = 0;i < 10;++ i) {
		int now = 0 , yi = 1 , rev = 0;
		for(int j = 1;j <= n;++ j) {
			if(s[j][0] =='|') {
				if(a[j] & (1 << i)) {
					yi = 0; now = 1;
				}
			}
			else if(s[j][0] =='&') {
				if(!(a[j] & (1 << i))) {
					yi = 0; now = 0;
				}
			}
			else if(s[j][0] == '^') if(a[j] & (1 << i)){
				if(yi) rev ^= 1; else now ^= 1;
			}
		}
		bit[i][0] = yi; bit[i][1] = (bit[i][0]) ? rev : now;
	}
	
	int a = 1023 , b = 0, c = 0;
	
	for(int i = 0;i < 10;++ i) {
		if(!bit[i][0]) {
			if(!bit[i][1]) a ^= (1 << i); else b |= (1 << i);
		}
		else if(bit[i][1]) c |= (1 << i);
	}
	cout << 3 << endl;
	cout << "&" <<" "<< a << endl;
	cout << "|" <<" "<< b << endl;
	cout << "^" <<" "<< c << endl;
}