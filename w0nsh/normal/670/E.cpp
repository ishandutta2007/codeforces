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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, p;
	std::cin >> n >> m >> p;
	p--;
	std::string str;
	std::cin >> str;
	VI left(n), right(n), my(n);
	FOR(i, n) left[i] = i-1, right[i] = i+1;
	right[n-1] = -1;
	left[0] = -1;
	std::stack<int> stack;
	FOR(i, n){
		if(str[i] == '(') stack.push(i);
		else{
			my[stack.top()] = i;
			my[i] = stack.top();
			stack.pop();
		}
	}
	FOR(_, m){
		char op;
		std::cin >> op;
		if(op == 'R'){
			p = right[p];
		}else if(op == 'L'){
			p = left[p];
		}else{
			int l = my[p];
			int r = p;
			if(l > r) std::swap(l, r);
			int lll = left[l];
			int rr = right[r];
			if(lll != -1) right[lll] = rr;
			if(rr != -1) left[rr] = lll;
			if(rr != -1) p = rr;
			else p = lll;
		}
	}
	while(left[p] != -1) p = left[p];
	do{
		std::cout << str[p];
		p = right[p];
	}while(p != -1);
	return 0;
}