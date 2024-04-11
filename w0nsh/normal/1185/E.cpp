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

int t, n, m;
int tab[2005][2005];
int draw[2005][2005];

const PR<PII, PII> XD = MP(MP(-1, -1), MP(-1, -1));
const PR<PII, PII> BAD = MP(MP(-2, -2), MP(-2, -2));

PR<PII, PII> get_line(const std::vector<PII> &vec){
	if(SZ(vec) == 0) return XD;
	if(SZ(vec) == 1) return MP(vec[0], vec[0]);
	if(vec[0].X == vec[1].X){
		int min = vec[0].Y;
		int max = vec[0].Y;
		TRAV(i, vec){
			if(i.X != vec[0].X) return BAD;
			min = std::min(i.Y, min);
			max = std::max(i.Y, max);
		}
		return MP(MP(vec[0].X, min), MP(vec[0].X, max));
	}else if(vec[0].Y == vec[1].Y){
		int min = vec[0].X;
		int max = vec[0].X;
		TRAV(i, vec){
			if(i.Y != vec[0].Y) return BAD;
			min = std::min(i.X, min);
			max = std::max(i.X, max);
		}
		return MP(MP(min, vec[0].Y), MP(max, vec[0].Y));
	}
	return BAD;
}

void dr(PR<PII, PII> line, int c){
	if(line.X.X == line.Y.X){
		REP(i, line.X.Y, line.Y.Y+1) draw[line.X.X][i] = c;
	}else{
		REP(i, line.X.X, line.Y.X+1) draw[i][line.X.Y] = c;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		FOR(i, n) FOR(j, m) tab[i][j] = -1;
		FOR(i, n) FOR(j, m) draw[i][j] = -1;
		int k = -1;
		std::vector<std::vector<PII> > pos(26);
		FOR(i, n) FOR(j, m){
			char a;
			std::cin >> a;
			if(a == '.') tab[i][j] = -1;
			else tab[i][j] = a-'a', k = std::max(k, (int)(a-'a')), pos[a-'a'].push_back(MP(i, j));
		}
		k++;
		if(k == 0){
			std::cout << "YES\n0\n";
			continue;
		}
		std::vector<PR<PII, PII> > lines;
		bool good = true;
		FOR(i, k){
			PR<PII, PII> line = get_line(pos[i]);
			if(line == BAD){
				good = false;
				break;
			}
			if(line != XD) dr(line, i);
			lines.push_back(line);
		}
		if(!good){
			std::cout << "NO\n";
			continue;
		}
		FOR(i, n){
			FOR(j, m){
				if(tab[i][j] != draw[i][j]){
					good = false;
					break;
				}
			}
			if(!good) break;
		}
		if(!good) std::cout << "NO\n";
		else{
			std::cout << "YES\n" << k << "\n";
			int ile = 0;
			FOR(i, k){
				if(lines[i] == XD) ile++;
				else{
					ile++;
					while(ile > 0){
						std::cout << lines[i].X.X+1 << " " << lines[i].X.Y+1 << " " << lines[i].Y.X+1 << " " << lines[i].Y.Y+1 << "\n";
						ile--;
					}
				}
			}
		}

	}
	return 0;
}