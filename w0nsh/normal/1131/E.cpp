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

const ll INF = 1000000006;
int n;
ll lng[26], lc[26];
ll start, end;

void count_lc(std::string &str){
	start = SZ(str);
	FOR(i, SZ(str)) if(str[i] != str[0]){
		start = i;
		break;
	}
	end = SZ(str);
	for(int i = SZ(str)-1; i >= 0; --i) if(str[i] != str.back()){
		end = SZ(str)-1-i;
		break;
	}
	char cur = '1';
	ll cnt = 1;
	FOR(i, 26) lc[i] = 0;
	FOR(i, SZ(str)){
		if(str[i] != cur){
			if(cur != '1') lc[cur-'a'] = std::max(lc[cur-'a'], cnt);
			cnt = 1;
			cur = str[i];
		}else cnt++;
	}
	lc[cur-'a'] = std::max(lc[cur-'a'], cnt);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::string str;
	std::cin >> str;
	count_lc(str);
	FOR(i, 26) lng[i] = lc[i];
	FOR(_, n-1){
		std::cin >> str;
		count_lc(str);
		FOR(i, 26) if(i != str[0]-'a' && i != str.back()-'a') lng[i] = std::min(lng[i], 1ll);
		if(start == SZ(str)){
			lng[str[0]-'a'] = 1ll*(lng[str[0]-'a']+1)*start+lng[str[0]-'a'];
		}else if(str[0] == str.back()){
			if(lng[str[0]-'a'] > 0) lng[str[0]-'a'] = start + end + 1;
		}else{
			if(lng[str[0]-'a'] > 0) lng[str[0]-'a'] = start + 1;
			if(lng[str.back()-'a'] > 0) lng[str.back()-'a'] = end+1;
		}
		FOR(i, 26) lng[i] = std::max(lng[i], lc[i]);
		FOR(i, 26) if(lng[i] > INF) lng[i] = INF;
	}
	ll mx = 0;
	FOR(i, 26) mx = std::max(mx, lng[i]);
	std::cout << mx; 
	return 0;
}