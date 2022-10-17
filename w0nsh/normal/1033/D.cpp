#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

const ll MOD = 998244353;

int n;
std::vector<ll> A;
std::vector<PII> what;
std::map<ll, int> map;
std::map<ll, int> unk;
ll gc[505][505];

ll second(ll a){
	ll left = 1;
	ll right = 1900000000ll;
	while(left < right){
		ll mid = (left+right)/2ll;
		if(mid*mid == a) return mid;
		if(mid*mid < a) left = mid+1;
		else right = mid; 
	}
	return -1;
}

ll third(ll a){
	ll left = 1;
	ll right = 1259924ll;
	while(left < right){
		ll mid = (left+right)/2ll;
		if(mid*mid*mid == a) return mid;
		if(mid*mid*mid < a) left = mid+1;
		else right = mid; 
	}
	return -1;
}


ll fourth(ll a){
	ll left = 1;
	ll right = 37609ll;
	while(left < right){
		ll mid = (left+right)/2ll;
		if(mid*mid*mid*mid == a) return mid;
		if(mid*mid*mid*mid < a) left = mid+1;
		else right = mid; 
	}
	return -1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	what.resize(n, MP(-1, -1));
	FOR(i, n) std::cin >> A[i];
	FOR(i, n){
		if(A[i] == 1) continue;
		ll c2 = second(A[i]);
		ll c3 = third(A[i]);
		ll c4 = fourth(A[i]);
		if(c4 != -1){
			what[i] = MP(c4, 4);
			map[c4] += 4;
		}else if(c3 != -1){
			what[i] = MP(c3, 3);
			map[c3] += 3;
		}else if(c2 != -1){
			what[i] = MP(c2, 2);
			map[c2] += 2;
		}else what[i] = MP(A[i], 1);
	}
	FOR(i, n) REP(j, i, n) gc[i][j] = gc[j][i] = std::__gcd(A[i], A[j]);
	FOR(i, n){
		if(A[i] == 1) continue;
		if(what[i].Y == 1){
			FOR(j, n) if(gc[i][j] > 1 && gc[i][j] < A[i]){
				what[i].Y = 0;
				what[i].X = gc[i][j];
				map[gc[i][j]]++;
				map[A[i]/gc[i][j]]++;
				break;
			}
		}
	}
	FOR(i, n){
		if(A[i] == 1) continue;
		if(what[i].Y == 1) unk[what[i].X]++;
	}
	ll ans = 1;
	TRAV(pr, map) ans = (ans*(pr.Y+1))%MOD;
	TRAV(pr, unk) ans = (((ans*(pr.Y+1))%MOD)*(pr.Y+1))%MOD;
	std::cout << ans << "\n";
	return 0;
}