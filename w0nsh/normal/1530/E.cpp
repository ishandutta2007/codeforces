#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		std::string s;
		std::cin >> s;

		VI ile(26);
		FOR(i, SZ(s)) ile[s[i]-'a']++;

		int cnt = 0;
		FOR(i, 26) if(ile[i]) cnt++;
		if (cnt == 1 || SZ(s) <= 2){
			std::sort(s.begin(), s.end());
			std::cout << s << "\n";
			continue;
		}

		auto let = [&](int i){
			return 'a' + i;
		};

		auto INF = 'a' + 28;

		auto get_next = [&](VI tab, int co){
			REP(i, co+1, 26){
				if(tab[i]) return i;
			}
			return -1;
		};

		bool ok = false;
		FOR(i, 26) if(ile[i] == 1){

			std::string ret;
			ret.push_back('a' + i);
			ile[i]--;
			FOR(j, 26) while(ile[j]) ret.push_back('a' + j), ile[j]--;

			std::cout << ret << "\n";
			ok = true;
		}
		if(ok) continue;

		std::string cand;
		cand.push_back(INF);
		int ind = get_next(ile, -1);

		if(ile[ind] > 1){
			auto num = ile;
			cand = "";
			cand.push_back(let(ind));
			cand.push_back(let(ind));
			num[ind] -= 2;
			int heh = get_next(num, ind);
			assert(heh != -1);
			cand.push_back(let(heh));
			num[heh]--;
			
			int prev = heh;
			while(SZ(cand) < SZ(s)){
				if(prev == ind || num[ind] == 0){
					heh = get_next(num, ind);
					if(heh == -1){
						cand = "";
						cand.push_back(INF);
						break;
					}
					cand.push_back(let(heh));
					num[heh]--;
					prev = heh;
				}else{
					cand.push_back(let(ind));
					num[ind]--;
					prev = ind;
				}
			}
		}

		std::string dif;
		dif.push_back(INF);
		
		{
			dif = "";
			auto num = ile;
			dif.push_back(let(ind));
			num[ind]--;
			int heh = get_next(num, ind);
			dif.push_back(let(heh));
			num[heh]--;

			while(num[ind]){
				dif.push_back(let(ind));
				num[ind]--;
			}

			int xd = get_next(num, heh);
			if(xd == -1){
				dif ="";
				dif.push_back(INF);
			}else{
				dif.push_back(let(xd));
				num[xd]--;
				
				while(SZ(dif) < SZ(s)){
					auto guy = get_next(num, ind);
					dif.push_back(let(guy));
					num[guy]--;
				}
			}
		}
		
		std::string dwa;
		dwa.push_back(INF);

		{
			dwa = "";
			auto num = ile;
			dwa.push_back(let(ind));
			num[ind]--;
			int heh = get_next(num, ind);

			while(num[heh]){
				dwa.push_back(let(heh));
				num[heh]--;
			}

			while(SZ(dwa) < SZ(s)){
				heh = get_next(num, -1);
				assert(heh != -1);
				dwa.push_back(let(heh));
				num[heh]--;
			}
		}

		std::cout << std::min(std::min(cand, dif), dwa) << std::endl;

	}

	return 0;
}