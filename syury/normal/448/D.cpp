#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define y1 adjf

int n, m;
lint k;

lint f(lint x){
	lint res = 0ll;
	F(i, 1, n + 1){
		lint d = x/i;
		if(x % i == 0){d--;}
		d = min(d, (lint)m);
		res += d;
	}
	ret res;
}

lint solve(){
	lint l = 1, r = n * 1ll * m;
	while(r - l > 1){
		lint mid = (l + r) >> 1;
		if(f(mid) >= k){r = mid - 1;}
		else{l = mid;}
	}
	if(f(r) < k)
		ret r;
	ret l;
}

bool can(lint x){
	for(lint i = 1; i * i <= x; i++){
		if(x % i != 0){cont;}
		if(i <= max(n, m) && (x/i) <= min(n, m)){ret true;}
		if(i <= min(n, m) && (x/i) <= max(n, m)){ret true;}
	}
	ret false;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d%d%lld", &n, &m, &k);
	lint bnd = solve();
	Df(i, bnd, 0){
		if(can(i)){printf("%lld", i); ret 0;}
	}
	ret 0;
}