#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n;
VI A;
ll pref[500005];
ll spref(int a, int b){
	return pref[b+1]-pref[a];
}
int thr[500005];

void fail(){
	std::cout << -1 << "\n";
	std::exit(0);
}

int check(int x){
	bool lfail = false;
	bool rfail = false;
	VI nw = A;
	int my = n+1;
	nw.push_back(x);
	for(int i = n; i >= 1; --i){
		if(nw[i] > nw[i-1]) std::swap(nw[i], nw[i-1]), my--;
		else break;
	}
	int spad = 0;
	ll rsum = 0;
	REP(i, 1, SZ(nw)+1) pref[i] = pref[i-1]+nw[i-1];
	FOR(i, 500005) thr[i] = 0;
	for(int k = SZ(nw); k >= 1; --k){
		spad += thr[k];
		rsum -= spad;
		if(k < SZ(nw)){
			if(nw[k] < k){
				rsum += nw[k];
				if(nw[k] != 0) thr[nw[k]-1]++;
			}else{
				rsum += k;
				spad++;
			}
		}
		ll left = spref(0, k-1);
		ll right1 = 1ll*k*(k-1);
		if(left > right1+rsum){
			if(k < my) lfail = true;
			else rfail = true;
		}
	}
	if(lfail && rfail) fail();
	if(!lfail && !rfail) return 0;
	if(lfail) return -1;
	return 1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	int par = 0;
	FOR(i, n) std::cin >> A[i], par = (par+A[i])%2;
	std::sort(A.begin(), A.end(), std::greater<int>());
	int left = 0;
	int right = n+1;
	int good = -1;
	while(left < right){
		int mid = (left+right)/2;
		int c = check(mid);
		if(c == 0){
			good = mid;
			break;
		}
		if(c == 1) right = mid;
		else left = mid+1;
	}
	if(good == -1) fail();
	left = good;
	right = n+1;
	while(left < right){
		int mid = (left+right)/2;
		int c = check(mid);
		if(c != 0) right = mid;
		else left = mid+1;
	}
	int end = left-1;
	left = 0;
	right = good+1;
	while(left < right){
		int mid = (left+right)/2;
		int c = check(mid);
		if(c != 0) left = mid+1;
		else right = mid;
	}
	bool was = true;
	REP(i, left, end+1){
		if(i%2 == par) was = true, std::cout << i << " ";
	}
	if(!was) fail();
	return 0;
}