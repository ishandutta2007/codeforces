#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


namespace kactl{

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * License: CC0
 * Source: folklore
 * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of the type $(a\|\|b)\&\&(!a\|\|c)\&\&(d\|\|!b)\&\&...$ becomes true, or reports that it is unsatisfiable.
 * Negated variables are represented by bit-inversions (\texttt{\tilde{}x}).
 * Usage:
 *  TwoSat ts(number of boolean variables);
 *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
 *  ts.setValue(2); // Var 2 is true
 *  ts.atMostOne({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
 *  ts.solve(); // Returns true iff it is solvable
 *  ts.values[0..N-1] holds the assigned values to the vars
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 * Status: stress-tested
 */

struct TwoSat {

	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};
};

using kactl::TwoSat;


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numWord, numLetter; std::cin>>numWord>>numLetter;
	TwoSat data(numLetter); // true=capitalize (smaller)
	auto const readVector=[&]{
		int len; std::cin>>len;
		std::vector<int> result(len);
		for(auto & it: result){std::cin>>it;--it;}
		return result;
	};
	std::vector<int> last=readVector();
	for(int _=0; _<numWord-1; ++_){
		auto cur=readVector();
		unsigned i=0;
		while(i<std::min(last.size(), cur.size()) and last[i]==cur[i]) ++i;
		if(i!=last.size()){
			if(i==cur.size()){
				std::cout<<"No\n";
				return 0;
			}
			auto const a=last[i], b=cur[i];
			assert(a!=b);
			if(a<b){
				data.either(a, ~b);
			}else{
				data.setValue(a);
				data.setValue(~b);
			}
		}
		last=std::move(cur);
	}
	if(not data.solve()){
		std::cout<<"No\n";
		return 0;
	}
	
	std::cout<<"Yes\n";
	int k{};
	for(int i=0; i<numLetter; ++i)
		if(data.values[i]) ++k;
	std::cout<<k<<'\n';
	for(int i=0; i<numLetter; ++i)
		if(data.values[i]) std::cout<<i+1<<' ';
	std::cout<<'\n';

}