#include <bits/stdc++.h>

typedef long long ll;

const int N = 500000;

char s[N + 5]; ll ans; int n;

struct node{int l, r, x;};
int main() {
	scanf("%d%s", &n, s + 1);
	
	std::stack<node>stk; ll nw = 0;
	for(int i=1,t=0;i<=n;i++) {
		if( s[i] == '0' ) {
			if( t ) stk.push((node){1, t, i - 1});
			t = 0;
		} else {
			if( stk.empty() ) nw += i;
			else {
				node p = stk.top(); stk.pop();
				nw += (i - p.x), p.l++, p.x--;
				if( p.l <= p.r ) stk.push(p);
			}
			t++;
		}
		ans += nw;
	}
	printf("%lld\n", ans);
}