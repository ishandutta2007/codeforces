#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define getchar _getchar_nolock
#define putchar _putchar_nolock

//OP IO
inline int in() {
	int result = 0;
	char ch = getchar();
	while (true) {
		if(ch >= '0' && ch <= '9')
			break;
		ch = getchar();
	}
	result = ch-'0';
	while(true) {
		ch = getchar();
		if (ch < '0' || ch > '9')
			break;
		result = result*10 + (ch - '0');
	}
	return result;
}
inline void out(int x) {
    if(x==-1) {
        putchar('-');
        putchar('1');
        putchar('\n');
        return;
    }
	int rev=x, count = 0;
	if(x == 0) {
putchar('0');
putchar('\n');
return;
}
	while((rev % 10) == 0) {
++count;
rev /= 10;
} //obtain the count of the number of 0s
	rev = 0;
	while(x != 0) {
rev = rev*10 + x % 10;
x /= 10;
} //store reverse of N in rev
	while(rev != 0) {
putchar(rev % 10 + '0');
rev /= 10;
}
	while(count--)
putchar('0');
	putchar('\n');
}

const int mxN=3e5;
int n, q, a[mxN], lc[mxN];
vector<int> occ[mxN], tc;

unsigned int rng_seed=69;
inline unsigned int rng() {
	rng_seed^=rng_seed<<13;
	rng_seed^=rng_seed>>17;
	rng_seed^=rng_seed<<5;
	return rng_seed;
}

int main() {
	n=in(), q=in();
	for(int i=0; i<n; ++i)
		occ[a[i]=in()-1].push_back(i);
	for(int qi=1; qi<=q; ++qi) {
		int l=in()-1, r=in()-1, k=in(), len=r-l+1, ans=-1;
		for(int it=0; it<70; ++it) {
			int i=l+rng()%len;
			if(lc[a[i]]==qi)
				continue;
			lc[a[i]]=qi;
			if(upper_bound(occ[a[i]].begin(), occ[a[i]].end(), r)-upper_bound(occ[a[i]].begin(), occ[a[i]].end(), l-1)>(r-l+1)/k&&(ans==-1||a[i]+1<ans))
				ans=a[i]+1;
		}
		out(ans);
	}
}