#include <bits/stdc++.h>
using namespace std;
#define M 100010
#define LL long long
#define rep(i, x, y) for(LL i = (x); i <= (y); i ++)
inline LL read() {
	char ch = getchar(); LL x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	} while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	} return x * f;
}

LL t[M];
LL n, m, a, d;
LL x;
inline LL calc_num(LL l, LL r) {
	LL w = l / a; if(a * w != l) w ++;
	l = w * a; r = min(r, n * a);
	if(l > r) return 0;
	LL ret = (r - l + 1) / a + 1;
	if((r - l + 1) % a == 0) ret --;
	return ret;
}
inline LL calc_now(LL l, LL r, LL X) {
	LL w = l / a; if(a * w != l) w ++;
	l = w * a; l += X; 
	return l;
}
int main(){
///	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	n = read(), m = read(), a = read(), d = read() + 1;
	rep(i, 1, m) t[i] = read();
	x = d / a + 1;  if(d % a == 0) x --;  
	//printf("x: %d\n", x);
	sort(t + 1, t + m + 1); LL now = 0;
	LL ans = 0; if(n * a > t[m]) t[m + 1] = n * a; 
	if(a < t[1]) {
		LL num = calc_num(a, t[1] - 1);
		ans += num / x; //printf("num : %d\n", num);
		if(num % x != 0) {
			now = calc_now(a, t[1] - 1, (num / x) * x * a) + d - 1;
			ans ++;
		} else if((num / x)) now = calc_now(a, t[1] - 1, (num / x) * x * a - x * a) + d - 1;
		//printf("now : %lld\n", now);
	} rep(i, 1, m) {
		now = max(t[i] - 1, now);
		while(now < t[i]) {
			now += d; ans ++;
		} if(now < t[i + 1] - 1) {
			LL num = calc_num(now + 1, t[i + 1] - 1);
			ans += num / x; //printf("num : %lld\n", num % x);
			if(num % x != 0) {
				now = calc_now(now + 1, t[i + 1] - 1, (num / x) * x * a) + d - 1;
				ans ++;
			} else if((num / x)) now = calc_now(now + 1, t[i + 1] - 1, (num / x) * x * a - x * a) + d - 1;
		} //printf("now : %lld %lld\n", now, ans);
	} now = max(t[m + 1] - 1, now);
	while(now < t[m + 1]) {
		now += d; ans ++;
	} cout << ans;
	return 0;
}
/*
4 5 2 10
16 17 17 13 11 
*/