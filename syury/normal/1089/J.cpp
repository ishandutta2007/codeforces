#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define cont continue
#define ret return
#define brk break
#define mp make_pair
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define ins insert
#define int ll

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 41 * 81 * 300 + 2;

enum ttp{
	reserved,
	number,
	word,
	no
};

struct Trie{
	struct node{
		map<char, int> nxt;
		ttp final_type = no;
	};
	vector<node> t;
	Trie(){
		t.resize(1);
	}
	void add_string(const string & s, ttp type){
		int v = 0;
		I(c, s){
			if(!t[v].nxt.count(c)){
				t[v].nxt[c] = t.size();
				t.push_back(node());
			}
			v = t[v].nxt[c];
		}
		t[v].final_type = type;
	}
};

set<string> tok;
Trie all_tokens;
vector<string> lines;
string curr_rep = "a";
ttp token_type[N];
map<string, string> raw_words;
string token_string[N];
int sz = 0;
Trie res_trie;
int dp[N];
bool can[N];

string gen_next(string s){
	int pos = s.length();
	--pos;
	while(pos >= 0 && s[pos] == 'z')
		--pos;
	if(pos == -1){
		string t = "";
		F(i, 0, s.length() + 1)
			t += 'a';
		return t;
	}
	++s[pos];
	F(i, pos + 1, s.length())s[i] = 'a';
	return s;
}

bool is_reserved(string s){
	int v = 0;
	I(c, s){
		if(!res_trie.t[v].nxt.count(c))ret 0;
		v = res_trie.t[v].nxt[c];
	}
	return res_trie.t[v].final_type == reserved;
}

string next_string(string & s){
	string old = s;
	while(is_reserved(old)){
		old = gen_next(old);
		s = old;
	}
	do{
		s = gen_next(s);
	}while(is_reserved(s));
	return old;
}

inline bool isnumchar(char c){
	return c >= '0' && c <= '9';
}

inline bool iswordchar(char c){
	return isnumchar(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '$' || c == '_';
}

string get_word(string s){
	if(raw_words.count(s))
		return raw_words[s];
	else return raw_words[s] = next_string(curr_rep);
}

void first_parse(string s){
	//cout << "parsing " << s << endl;
	size_t pos = 0;
	while(pos < s.length()){
		int v = 0;
		bool is_word;
		if(s[pos] >= '0' && s[pos] <= '9')is_word = false;
		else is_word = true;
		int rpa = 0, wpa = 0;
		if(!is_word){
			while(pos + wpa < s.length()){
				if(!isnumchar(s[pos + wpa]))break;
				++wpa;
			}
		}
		else{
			while(pos + wpa < s.length()){
				if(!iswordchar(s[pos + wpa]))break;
				++wpa;
			}
		}
		int cu = 0;
		while(pos + cu < s.length()){
			char c = s[pos + cu];
			if(!res_trie.t[v].nxt.count(c))break;
			v = res_trie.t[v].nxt[c];
			if(res_trie.t[v].final_type == reserved)
				rpa = max(rpa, cu + 1);
			++cu;
		}
		int len = max(wpa, rpa);
		string token = s.substr(pos, len);
		if(is_word && wpa > rpa){
			token = get_word(token);
		}
		token_string[sz] = token;
		token_type[sz] = wpa > rpa ? is_word ? word : number : reserved;
		++sz;
		pos += len;
	}
}

int from[N];

void upd_dp(int x, int y){
	if(dp[x] == -1 || dp[x] > dp[y] + 1){
		dp[x] = dp[y] + 1;
		from[x] = y;
	}
}

string sup;
size_t startpos[N];
size_t endpos[N];
vector<int> can_parse[N];

signed main(){
#ifdef LOCAL
    freopen("Jin.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n_tokens;
	cin >> n_tokens;
	F(i, 0, n_tokens){
		string s;
		cin >> s;
		I(c, s)assert(c >= 33);
		tok.ins(s);
		res_trie.add_string(s, reserved);
	}
	string s;
	getline(cin, s);
	I(c, s)assert(c < 33);
	int n_lines;
	cin >> n_lines;
	getline(cin, s);
	F(i, 0, n_lines){
		getline(cin, s);
		size_t pos = s.find_first_of('#');
		if(pos != string::npos)
			s = s.substr(0, pos);
		if(s.empty())continue;
		lines.pb(s);
		int L = s.length();
		vector<string> raw;
		string la = "";
		F(j, 0, L){
			assert(s[j] >= 32);
			if(s[j] == ' '){
				if(!la.empty())raw.pb(la);
				la = "";
			} else la += s[j];
		}
		if(!la.empty())raw.pb(la);
		I(t, raw){
			first_parse(t);
		}
	}
	//I(x, raw_words)
	//	all_tokens.add_string(x.Y, word);
	//I(s, tok)all_tokens.add_string(s, reserved);
	all_tokens = res_trie;
	F(i, 0, sz){
		startpos[i] = sup.length();
		sup += token_string[i];
	}
//	if(sup.empty()){cout << endl; return 0;}
	//cout << sup << endl;
	fill(dp + 1, dp + 3 + sz, -1);
	dp[0] = 0;
	int L = sup.length();
	DF(i, L - 1, 0){
		int add = 0;
		int v = 0;
		bool num = 1, wrd = 1;
		if(isnumchar(sup[i]))wrd = 0;
		while(i + add < L){
			if(!iswordchar(sup[i + add]))wrd = 0;
			if(!isnumchar(sup[i + add]))num = 0;
			if(v != -1 && !all_tokens.t[v].nxt.count(sup[i + add]))v = -1;
			if(v != -1)v = all_tokens.t[v].nxt[sup[i + add]];
			if(wrd || num || (v != -1 && all_tokens.t[v].final_type != no))
				can_parse[i].pb(i + add + 1);
			++add;
		}
		/*cout << "can in " << i << endl;
		I(x, can_parse[i])cout << x << ' ';
		cout << endl;*/
	}
	endpos[0] = 0;
	F(i, 1, sz + 1)endpos[i] = startpos[i - 1] + token_string[i - 1].length();
	F(i, 0, sz){
		assert(dp[i] != -1);
		if(dp[i] == -1)continue;
		int up = (int)1e9;
		F(j, i + 1, sz + 1){
			if(up <= endpos[j])
				break;
			auto it = upper_bound(all(can_parse[endpos[j - 1]]), endpos[j]) - can_parse[endpos[j - 1]].begin();
//			assert(it && can_parse[endpos[j - 1]][it - 1] == endpos[j]);
			if(it != can_parse[endpos[j - 1]].size()){
			up = min(up, can_parse[endpos[j - 1]][it]);
			//cout << endpos[j] << ' ' << can_parse[endpos[j - 1]][it] << endl;
			}
			upd_dp(j, i);
		}
	}
	vector<int> must_space;
	int v = sz;
	while(v){
		if(v != sz)must_space.pb(endpos[v]);
		v = from[v];
	}
	int ptr = 0;
	reverse(all(must_space));
	F(i, 0, L){
		if(ptr < (int)must_space.size() && must_space[ptr] == i){
			cout << ' ';
			++ptr;
		}
		cout << sup[i];
	}
	return 0;
}