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

char ex[3] = {'0', 'a', 'A'};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	int what[105];
	while(t--){
		std::string s;
		std::cin >> s;
		int ind = 0;
		int cnt[3];
		cnt[1] = cnt[2] = cnt[0] = 0;
		TRAV(ch, s){
			if(ch >= '0' && ch <= '9') what[ind] = 0, cnt[0]++;
			if(ch >= 'a' && ch <= 'z') what[ind] = 1, cnt[1]++;
			if(ch >= 'A' && ch <= 'Z') what[ind] = 2, cnt[2]++;
			ind++;
		}
		FOR(i, 3) if(cnt[(i+1)%3] + cnt[(i+2)%3] == 0){
			s[0] = ex[(i+1)%3];
			s[1] = ex[(i+2)%3];
			break;
		}
		ind = 0;
		cnt[1] = cnt[2] = cnt[0] = 0;
		TRAV(ch, s){
			if(ch >= '0' && ch <= '9') what[ind] = 0, cnt[0]++;
			if(ch >= 'a' && ch <= 'z') what[ind] = 1, cnt[1]++;
			if(ch >= 'A' && ch <= 'Z') what[ind] = 2, cnt[2]++;
			ind++;
		}
		int sub = -1;
		int rep = -1;
		FOR(i, 3) if(cnt[i] == 0) rep = i, sub = (cnt[(i+1)%3] == 1 ? (i+2)%3 : (i+1)%3);
		if(sub != -1) FOR(i, SZ(s)) if(what[i] == sub){
			s[i] = ex[rep];
			break;
		}
		std::cout << s << "\n";
	}
	return 0;
}