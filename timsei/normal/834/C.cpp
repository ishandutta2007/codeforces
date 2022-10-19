#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x,int y) {
	return y==0?x:gcd(y , x%y);
}

int n , m;

void onecase() {
	scanf("%lld%lld",&n, &m);
	int G = gcd(n , m);
	int nn = n /G , mm = m / G;
	if(m %nn !=0 || n % mm !=0 || n %(nn * nn  *mm) != 0 || m %(mm *mm *nn) !=0) {
		puts("No");return;
	}
	n /=(nn * nn *mm);
	m /= (mm *mm *nn);
	if(n !=m ) {
		puts("No");return ;
	}
	int  l = 1 , r= 1e5;
	bool ok = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(mid * mid * mid >n) {
			r = mid -1;
		}
		else  {
			if(mid * mid * mid ==n) {
				ok = 1;break;
			}
			l = mid +1;
		}
	}
	if(ok) {
		puts("Yes");return ;
	}
	puts("No");
}

signed main() {
	int t ;
	for(scanf("%lld",&t);t -->0;) {
		onecase();
	}
}