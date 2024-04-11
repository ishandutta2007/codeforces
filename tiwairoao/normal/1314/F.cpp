#include <bits/stdc++.h>

typedef unsigned long long ull;

ull nim[256][256]; // 
ull multiply(ull x,ull y,int len=32) {
    if(x==0||y==0) return 0;
    if(x==1||y==1) return x*y;
    if(len<=4&&nim[x][y]) return nim[x][y];
    ull xa=x>>len,xb=x^(xa<<len),ya=y>>len,yb=y^(ya<<len);
    ull a=multiply(xb,yb,len>>1),b=multiply(xa^xb,ya^yb,len>>1),c=multiply(xa,ya,len>>1),d=multiply(c,1ull<<len-1,len>>1);
    ull re=((b^a)<<len)^a^d;
    if(len<=4) nim[x][y]=re;
//	debug("%llu %llu %llu\n",x,y,re);
    return re;
}

ull mpow(ull b, ull p) {
	ull r = 1; for(; p; p >>= 1, b = multiply(b, b))
		if( p & 1 ) r = multiply(r, b);
	return r;
}

std::vector<ull>dv;
void init(ull x) {
	for(ull i=2;i*i<=x;i++) {
		while( x % i == 0 ) x /= i, dv.push_back(i);
	}
	if( x != 1 ) dv.push_back(x);
}

bool flag;
ull find(ull a, ull b, ull p) {
	ull sq = (ull)sqrt(p) + 1; std::map<ull, ull>mp;
	
	ull tmp = 1;
	for(ull i=0;i<=sq;i++) {
		mp[multiply(tmp, b)] = i;
		if( i != sq ) tmp=multiply(tmp, a);
	}
	
	ull tmp2 = tmp;
	for(ull i=sq;i-sq<=p;i+=sq,tmp=multiply(tmp,tmp2))
		if( mp.count(tmp) ) return i - mp[tmp];
		
	flag = false; return 0;
}

ull solve(ull a, ull b) {
	ull n = (~0), c = 1, ans = 0;
	for(auto p : dv) {
		ull r = find(mpow(a, n / p), mpow(b, n / p), p);
		if( !flag ) return 0;
		b = multiply(b, mpow(a, n - r)), a = mpow(a, p);
		ans += c * r, c *= p, n /= p;
	}
	return ans;
}

int main() {
	init((1ull << 32) - 1), init((1ull << 32) + 1);
	
	int t; ull a, b; scanf("%d", &t);
	while( t-- ) {
		scanf("%llu%llu", &a, &b), flag = true;
		ull ans = solve(a, b);
		if( flag && mpow(a, ans) != b ) {
			puts("!!!");
		}
		if( !flag ) puts("-1"); else printf("%llu\n", ans);
	}
}