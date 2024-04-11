#include <bits/stdc++.h>

const int B = 1000;

int N, S, D;

int a[B + 5], s; std::bitset<B>b[B + 5], x;
int insert() {
	int ns = 0;
	for(int i=N-1;i>=0;i--) {
		if( x[i] == 1 ) {
			if( a[i] ) x ^= b[i], ns ^= a[i];
			else {
				b[i] = x, a[i] = ns ^ (1 << (s++));
				return -1;
			}
		}
	}
	return ns;
}
int query() {
	int ns = 0;
	for(int i=N-1;i>=0;i--) {
		if( x[i] == 1 ) {
			if( b[i][i] == 1 ) x ^= b[i], ns ^= a[i];
			else return -1;
		}
	}
	return ns;
}

int lowbit(int k) {return k & -k;}
int bts(int k) {
	int c = 0;
	while( k ) c++, k ^= lowbit(k);
	return c;
}

int dp[1 << 20], tmp[1 << 20];
std::vector<int>v;
int main() {
	scanf("%d%d%d", &N, &S, &D);
	for(int i=0,k,p;i<S;i++) {
		x = 0, scanf("%d", &k);
		for(int j=1;j<=k;j++) scanf("%d", &p), p--, x[p] = 1;
		
		p = insert();
		if( p != -1 ) v.push_back(p);
	}
	
//	assert(s + (int)v.size() == S);
	if( s <= 20 ) {
		int t = (1 << s);
		for(int i=1;i<t;i++) dp[i] = dp[i >> 1] + (i & 1);
		for(auto k : v) {
			for(int i=0;i<t;i++) dp[i] = std::min(dp[i ^ k] + 1, dp[i]);
		}
	} else {
		int t = (1 << v.size());
		for(int i=0;i<t;i++)
			for(unsigned p=0;p<v.size();p++)
				if( (i >> p) & 1 ) tmp[i] ^= v[p];
	}
	
	for(int i=1,k,p;i<=D;i++) {
		x = 0, scanf("%d", &k);
		for(int j=1;j<=k;j++) scanf("%d", &p), p--, x[p] = 1;
		
		p = query();
		if( p != -1 ) {
			if( s <= 20 ) printf("%d\n", dp[p]);
			else {
				int t = (1 << v.size()), ans = 100;
				for(int j=0;j<t;j++)
					ans = std::min(ans, bts(p ^ tmp[j]) + bts(j));
				printf("%d\n", ans);
			}
		} else puts("-1");
	}
}