#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

int n , m , cl , ce , v;

set <int> L , E;

struct Query {
	int x1 , x2 , y1 , y2;
	void input(void) {
		scanf("%lld%lld%lld%lld" , &x1 , &x2 , &y1 , &y2);
		if(x1 > x2) swap(x1 , x2);
		if(y1 > y2) swap(y1 , y2);
	}
}Q[N];

bool check(set <int> & a , int x1 , int x2) {
	return (*(a.lower_bound(x1)) != (* a.lower_bound(x2)));
}

int calc(int x1 , int x2 , int who) {
	if(who >= x1 && who <= x2) return x2 - x1;
	if(who > x2) {
		return x2 - x1 + (who - x2) * 2;
	}
	else return x2 - x1 + (x1 - who) * 2;
}

vector <int> A , B;

void fuckL(int x1 , int x2 , int y1 , int y2 , int &ans) {
	set <int> ::iterator it = L.lower_bound(x1);
	A.clear();
	ans = min(ans , calc(x1 , x2 , *it) + y2 - y1);
	A.push_back(*it);
	-- it;
	ans = min(ans , calc(x1 , x2 , *it) + y2 - y1);
	A.push_back(*it);
	it = L.lower_bound(x2);
	ans = min(ans , calc(x1 , x2 , *it) + y2 - y1);
	A.push_back(*it);
	-- it;
	ans = min(ans , calc(x1 , x2 , *it) + y2 - y1);
	A.push_back(*it);
}

void fuckE(int x1 , int x2 , int y1 , int y2 , int &ans) {
	int tmp = ans;
	B.clear();
	set <int> ::iterator it = E.lower_bound(x1);
	int now = (y2 - y1 - 1) / v + 1;
	ans = min(ans , calc(x1 , x2 , *it) + now);
	B.push_back(*it);
	-- it;
	ans = min(ans , calc(x1 , x2 , *it) + now);
	B.push_back(*it);
	it = E.lower_bound(x2);
	ans = min(ans , calc(x1 , x2 , *it) + now);
	B.push_back(*it);
	-- it;
	ans = min(ans , calc(x1 , x2 , *it) + now);
	B.push_back(*it);
}

int d(int x , int y) {
	return (int)abs(y - x);
}

int fuck(int len) {
	return min(len / v + len % v , len / v + 1 + (v - len % v));
}

main(void) {
	scanf("%lld%lld%lld%lld%lld" , &n , &m , &cl , &ce , &v);
	for(int i = 1;i <= cl;++ i) {
		int x;
		scanf("%lld" , &x);
		L.insert(x);
	}
	L.insert(-1e10);
	L.insert(1e10);
	for(int i = 1;i <= ce;++ i) {
		int x;
		scanf("%lld" , &x);
		E.insert(x);
	}
	E.insert(-1e10);
	E.insert(1e10);
	int q = 0;
	for(cin >> q;q --;) {
		int x1 , x2 , y1 , y2 , ans = 1e18;
		set <int> ::iterator it;
		scanf("%lld%lld%lld%lld" , &x1 , &y1 , &x2 , &y2);
		swap(x1 , y1);
		swap(x2 , y2);
		if(x1 > x2) swap(x1 , x2);
		if(y1 > y2) swap(y1 , y2);
		fuckL(x1 , x2 , y1 , y2 , ans);
		fuckE(x1 , x2 , y1 , y2 , ans);
		if(y1 == y2) {
			ans = x2 - x1;
		}
		cout << ans << endl;
	}
}