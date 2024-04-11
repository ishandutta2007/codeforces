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

int n, m;
VI in[2], score;
std::vector<VI> g[2];

void xd(int kt){
	auto &cg = g[kt];
	auto &cin = in[kt];
	VI sc(n, -10);
	std::stack<int> stack;
	int good = n;
	FOR(i, n) if(cin[i] == 0) stack.push(i), good--;
	while(!stack.empty()){
		int cur = stack.top();
		stack.pop();
		if(SZ(stack) == 0) sc[cur] = good+1;
		else if(SZ(stack) == 1){
			int next = stack.top();
			sc[cur] = good+1;
			TRAV(ch, cg[next]) if(cin[ch] == 1){
				sc[cur] = -10;
				break;
			}
		}else sc[cur] = -10;
		TRAV(ch, cg[cur]){
			cin[ch]--;
			if(cin[ch] == 0) stack.push(ch), good--;
		}
	}
	FOR(i, n) score[i] += sc[i];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, 2) g[i].resize(n);
	FOR(i, 2) in[i].resize(n);
	score.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		in[0][b]++;
		in[1][a]++;
		g[0][a].push_back(b);
		g[1][b].push_back(a);
	}
	FOR(i, 2) xd(i);
	int cnt = 0;
	FOR(i, n) if(score[i] >= n) cnt++;
	std::cout << cnt << "\n";
	return 0;
}