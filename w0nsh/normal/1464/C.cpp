#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void ans(bool what){
	std::cout << (what ? "Yes\n" : "No\n");
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	ll t;
	std::cin >> n >> t;
	std::string s;
	std::cin >> s;
	VI A(n);
	FOR(i, n){
		A[i] = s[i]-'a';
	}
	t -= (1<<A.back());
	A.pop_back();
	t += (1<<A.back());
	A.pop_back();
	n -= 2;

	VI temp(26);
	FOR(i, n) temp[A[i]]++;
	std::vector<ll> have(100);
	FOR(i, 26){
		t += 1ll*(1<<i)*temp[i];
		have[i] = temp[i];
	}
	if(t < 0 || t%2 != 0){
		ans(0);
	}
	t /= 2;

	ll old = 0;
	FOR(i, 60){
		ll nw = have[i]+old;
		if(t & (1ll<<i)){
			if(nw == 0) ans(0);
			nw--;
		}
		old = nw/2;
	}
	ans(1);

	return 0;
}