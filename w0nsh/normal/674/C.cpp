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
typedef double ld; // change to long double

int n, k;
VI A;
ld pocz[200005], pref[200005], rev[200005];

ld f(int a, int b){
	// suma a <= i <= j <= b a[i]/a[j]
	ld have = pocz[b]-pocz[a-1];
	// wywalic z licznikow 1 + 2 + ... + a
	// odjac (1 + 2 + ... + a)*(1/a + 1/(a+1) + ...)
	have -= pref[a-1]*(rev[b]-rev[a-1]);
	return have;
}

struct CHT{
	struct Line{
		ld a, b;
		int ile;
		ld val(ld x){
			return a*x+b;
		}
		Line(){}
		Line(ld _a, ld _b, int _id) : a(_a), b(_b), ile(_id) {}
	};
	int place;
	std::vector<Line> stack;

	CHT(){
		place = 0;
		stack = std::vector<Line>();
	}

	ld przec(Line a, Line b){
		return (b.b-a.b)/(a.a-b.a);
	}

	void add_line(Line line){
		while(SZ(stack) >= 2 && przec(stack[SZ(stack)-2], line) <= przec(stack[SZ(stack)-2], stack.back())){
			stack.pop_back();
			if(place == SZ(stack)) place--;
		}
		stack.push_back(line);
	}

	PR<ld, int> min(ld x){
		while(place < SZ(stack)-1 && stack[place].val(x) >= stack[place+1].val(x))
			place++;
		return MP(stack[place].val(x), stack[place].ile);
	}	
};

PR<ld, int> check(ld p){
	// dp[i] = min k < i  dp[k]+fun(k+1, i)
	// dp[k] + pocz[i]-pocz[k]-pref[k]*(rev[i]-rev[k])
	// dp[k] + pocz[i] - pocz[k] - pref[k]*rev[i] + pref[k]*rev[k]
	// pocz[i] + (1, -rev[i]) (dp[k]-pocz[k]+pref[k]*rev[k], pref[k])
	CHT cht;
	cht.add_line(CHT::Line(0, 0, 0));
	REP(i, 1, n){
		PR<ld, int> cur = cht.min(rev[i]);
		cur.X += pocz[i];
		cht.add_line(CHT::Line(-pref[i], cur.X-pocz[i]+pref[i]*rev[i]+p, cur.Y+1));
	}
	PR<ld, int> ans = cht.min(rev[n]);
	return MP(ans.X+pocz[n]+p, ans.Y+1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	A.resize(n+1);
	REP(i, 1, n+1) std::cin >> A[i];
	ld sum = 0.0;
	REP(i, 1, n+1){
		sum += A[i];
		pocz[i] = pocz[i-1]+sum/A[i];
	}
	REP(i, 1, n+1) pref[i] = pref[i-1]+A[i];
	REP(i, 1, n+1) rev[i] = rev[i-1]+(1.0/A[i]);
	ld left = 0.0;
	ld right = 10000000000000000000.0;
	FOR(_, 110){
		ld mid = (right+left)/2;
		if(check(mid).Y <= k) right = mid;
		else left = mid;
	}
	PR<ld, int> ans = check(right);
	std::cout << std::fixed << std::setprecision(12) <<  ans.X-left*ans.Y << "\n";
	return 0;
}