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

int ask(int c, int d){
	std::cout << "? " << c << " " << d << "\n" << std::flush;
	int ret;
	std::cin >> ret;
	return ret;
}

void answer(int a, int b){
	std::cout << "! " << a << " " << b << "\n"  << std::flush;
	std::exit(0);
}

int tab[2][40];
int last_res = -2;

int query(int which, int kt){
	int c = 0, d = 0;
	FOR(i, 30){
		if(kt == 3){
			if(i != which){
				if(tab[0][i] == -1 || tab[0][i] == 1) c += (1<<i); 
				if(tab[1][i] == 1) d += (1<<i);
			}
			continue;
		}
		if(i == which){
			if(kt == 1) c += (1<<i);
			else d += (1<<i);
		}else{
			if(tab[0][i] == -1 || tab[0][i] == 1) c += (1<<i); 
			if(tab[1][i] == 1) d += (1<<i);
		}
	}
	int rt = ask(c, d);
	return rt;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	FOR(i, 2) FOR(j, 40) tab[i][j] = -1;
	for(int bt = 29; bt >= 0; --bt){
		int res1 = last_res;
		int res2 = -2;
		if(res1 == -2){
			res1 = query(bt, 1);
		}
		if(res2 == -2){
			res2 = query(bt, 2);
		}
		if(res1 == res2) last_res = res2;
		else last_res = -2;
		if(res1*res2 < 0){
			if(res1 == 1) tab[0][bt] = tab[1][bt] = 0;
			else tab[1][bt] = tab[0][bt] = 1;
		}else{
			int xd = query(bt, 3);
			if(xd == 1){
				tab[0][bt] = 1;
				tab[1][bt] = 0;
			}else if(xd == -1){
				tab[0][bt] = 0;
				tab[1][bt] = 1;
			}else{
				while(true) {}
			}
		}
	}
	int c = 0, d = 0;
	FOR(i, 30){
		if(tab[0][i] == 1) c += (1<<i); 
		if(tab[1][i] == 1) d += (1<<i);
	}
	answer(c, d);
	return 0;
}