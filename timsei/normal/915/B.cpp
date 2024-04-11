#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

int n , pos , l , r;

int main(void) {
	cin >> n >> pos >> l >> r;
	if(l == 1 && r == n) return 0 * puts("0");
	else {
		if(l == 1) return 0 * printf("%d\n" , abs(pos - (r)) + 1);
		if(r == n) return 0 * printf("%d\n" , abs(pos - l) + 1);
		//l , r;
		return printf("%d\n" , 2 + r - l + min(abs(l - pos) , abs(r - pos))) * 0;
	}
}