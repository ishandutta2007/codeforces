#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 3e5 + 5;

long long ans;
int x , y , n , lb , lr , lg , res = 0 , bb = 0 , br = 0;
char ch;

int main(void) {
	scanf("%d", &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%d" , &x);
		ch = ' ';
		while(ch != 'R' && ch != 'G' && ch != 'B') ch = getchar();
		if(ch == 'G') {
			if(lb) ans += x - lb , bb = max(x - lb , bb);
			if(lr) ans += x - lr , br = max(x - lr , br);
			if(lg && bb + br > x - lg) {
				ans -= bb + br;
				ans += x - lg;
			}
			lg = lr = lb = x;
			bb = br = 0;
		}
		else if(ch == 'B') {
			if(lb) {
				ans += x - lb;
				bb = max(bb , x - lb);
			}
			lb = x;
		}
		else {
			if(lr){
				ans += x - lr;
				br = max(br , x - lr);
			}
			lr = x;
		}
	}
	cout << ans;
}