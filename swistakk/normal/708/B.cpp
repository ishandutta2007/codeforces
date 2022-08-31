//Errichto's solution
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

void NO() {
	puts("Impossible");
	exit(0);
}

int f(int a) {
	int i = 0;
	while(true) {
		int maybe = i * (i - 1) / 2;
		if(maybe == a) return i;
		if(maybe > a) NO();
		++i;
	}
	assert(false);
}

int main() {
	int zeros, a01, a10, ones;
	scanf("%d%d%d%d", &zeros, &a01, &a10, &ones);
	int pairs = ones + zeros + a01 + a10;
	zeros = f(zeros);
	ones = f(ones);
	if(a01 == 0 && a10 == 0) {
		if(zeros && ones) NO();
		if(zeros == 0 && ones == 0) {
			puts("0");
			return 0;
		}
		if(zeros == 0) {
			REP(_, ones) printf("1");
			puts("");
			return 0;
		}
		assert(ones == 0);
		REP(_, zeros) printf("0");
		puts("");
		return 0;
	}
	if(zeros == 0) zeros = 1;
	if(ones == 0) ones = 1;
	int total = ones + zeros;
	if(total * (total - 1) != 2 * pairs) NO();
	//puts("a");
	for(int pref = zeros; true; --pref) {
		assert(pref >= 0);
		if((long long) pref * ones <= a01) {
			REP(_, pref) printf("0");
			int rem_zeros = zeros - pref;
			int rem = a01 - pref * ones;
			assert(rem <= ones);
			REP(_, ones - rem) printf("1");
			if(rem != 0 && rem != ones) {
				printf("0");
				rem_zeros--;
			}
			REP(_, rem) printf("1");
			REP(_, rem_zeros) printf("0");
			puts("");
			return 0;
		}
	}
	assert(false);
	return 0;
}