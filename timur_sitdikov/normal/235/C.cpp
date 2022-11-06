#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

// String automaton 
// O(n) time and O(n * k) memory for building (k = alphabet size)

// Use:
// Fill sa.s, sa.len (as strlen(sa.s))
// Call sa.build()

// Call sa.find_string(c) for finding string c in automaton (linear-tme)

// Automaton states will be in array sa.state.
// sa.state[0] corresponds to empty string,
// sa.state[sa.last] corresponds to the whole string,
// state[i].is_terminal is true for terminal (suffix) states,
// state[i].pos is the first position where corresponding substring appeared (index of its last symbol),
// state[i].cnt is the count of appearences of the corresponding substring in the string.

// For each state prv is the suffix link,
// len is the length of the longest string ending in the state
// to is array of links by symbols.

// Use state[i].is_terminal for finding suffixes of the string,
// Use state[i].pos for restoring substring for the state
// (the first index for state[i] is sa.state[i].pos - sa.state[i].len + 1, the last is sa.state[i].pos)

// Use sa.sorted_states as array of state indexes sorted by state.length
// (also it corresponds to topological sorting of states)
// (It can be used in dp)

// String maximal length
const int MAXLEN = 1e6 + 5;

// Alphabet size
const int MAXSZ = 26;

// Universal string helper (just for universal alphabets)
// Default alphabet is 'a'...'z'

// Change constructor for using other symbols
struct string_helper {
	int sym_ind[200];
	string_helper(){
		for(int i = 'a'; i <= 'z'; i++){
			sym_ind[i] = i - 'a';
		}
	}
};

string_helper st_helper;

// String automaton state
struct automaton_state {
	// Length of the longest string ending in current state
	int len;
	
	// Suffix link
	int	prv;
	
	// Links by symbols
	int to[MAXSZ];
	
	// Flag for terminal state
	bool is_terminal;
	
	// Count of appearences
	int cnt;
	
	// Index of first occurence in the string
	int pos;
};

struct suffix_automaton {
	// String
	char s[MAXLEN];
	
	// String length
	int len;
	
	// Automaton states
	automaton_state state[2 * MAXLEN];
	
	// Number of automaton states
	int sz;
	
	// Last state (corresponding to the end of the whole string)
	int last;
	
	// For counting sort by length
	int sort_count[MAXLEN];
	
	// Sorted states
	int sorted_states[2 * MAXLEN];
	
	// Init
	void init(){
		// Clear old data
		for(int i = 0; i < 2 * len; i++){
			state[i].len = 0;
			state[i].prv = -1;
			for(int j = 0; j < MAXSZ; j++){
				state[i].to[j] = -1;
			}
			state[i].is_terminal = false;
			state[i].cnt = 0;
			state[i].pos = -1;
		}
		
		// Add state for empty string
		state[0].len = 0;
		state[0].prv = -1;
		last = 0;
		sz = 1;
	}
	
	// Append indth symbol og string s
	void append_sym(int ind){
		int cur = sz++, p, q, q_copy;
		char c = st_helper.sym_ind[s[ind]];
		
		// New length
		state[cur].len = state[last].len + 1;
		
		// Init count of appearences (set 1)
		state[cur].cnt = 1;
		
		// Set index of first occurence
		state[cur].pos = ind;
		
		// p <- ... <- last
		// |			|
		// |			|
		// q		   cur
		
		// Calc state[p] having to[c]
		for(p = last; p != -1 && state[p].to[c] == -1; p = state[p].prv){
			state[p].to[c] = cur;
		}
		// No such p
		if (p == -1){
			state[cur].prv = 0;
		} else {
			// q = state[p].to[c]
			int q = state[p].to[c];
			
			// state[q] has suitable len
			if (state[p].len + 1 == state[q].len){
				state[cur].prv = q;
			} else {
				// state[q].len is too long - create new state from it and change necessary to and prv
				
				// ... <- ... <- p <- ... <- last
				// 			|	/ 			  |
				// 			|  /	 		  |
				//	     q_copy <- q	     cur
				
				int q_copy = sz++;
				// Copy state
				state[q_copy].prv = state[q].prv;
				for(int j = 0; j < MAXSZ; j++){
					state[q_copy].to[j] = state[q].to[j];
				}
				state[q_copy].pos = state[q].pos;
				// Set new length
				state[q_copy].len = state[p].len + 1;
				// Init count (set 0)
				state[q_copy].cnt = 0;
				
				// Reset to[c] for predecessors of p to q_copy
				for(; p != -1 && state[p].to[c] == q; p = state[p].prv){
					state[p].to[c] = q_copy;
				}
				
				// Reset prv for q
				state[q].prv = q_copy;
				// Set prv for cur
				state[cur].prv = q_copy;
			}
		}
		last = cur;
	}
	
	// Filling states by appending symbols
	// Call only after init()
	void fill_all_states(){
		// Append symbols
		for(int i = 0; i < len; i++){
			append_sym(i);
		}
	}
	
	// Mark terminal states
	// Call only after fill_all_states()
	void mark_terminate_states(){
		for(int p = last; p; p = state[p].prv){
			state[p].is_terminal = true;
		}
	}
		
	// Sort states by length (note it also corresponds to topological sorting)
	// Use counting sort which is linear-time
	// Call only after fill_all_states()
	void top_sort(){
		// Counting sort by state.len
		for(int i = 0; i <= len; i++){
			sort_count[i] = 0;
		}
		for(int i = 0; i < sz; i++){
			sort_count[state[i].len]++;
		}
		for(int i = 1; i <= len; i++){
			sort_count[i] += sort_count[i - 1];
		}
		for(int i = 0; i < sz; i++){
			sorted_states[--sort_count[state[i].len]] = i;
		}
	}
	
	// Calc count of appearence for every state
	// Call only after top_sort()
	void calc_count(){		
		// Go from the longest state and update by suffix link
		for(int i = sz - 1; i >= 0; i--){
			// Current state
			int cur = sorted_states[i];
			// Suffix link
			int prv = state[cur].prv;
			// Update only state representing non-empty string
			if (prv > 0){
				state[prv].cnt += state[cur].cnt;
			}
		}
	}
	
	// Build automaton
	void build(){
		// Init
		init();
		
		// Fill all states (to, link)
		fill_all_states();
		
		// Mark terminal states
		mark_terminate_states();
		
		// Topological sort (just sort states by length)
		top_sort();
		
		// Calc count of appearences
		calc_count();
	}
	
	int query_index[2 * MAXLEN];
	
	void print_state(int sym_ind, int state_index, int matched_len) {
		/*printf("%d: %d", sym_ind, state_index);
		printf(", len: %d", state[state_index].len);
		printf(", cnt: %d", state[state_index].cnt);
		printf(", to[a]: %d", state[state_index].to[0]);
		printf(", pos: %d", state[state_index].pos);
		printf(", prv_len: %d", state_index == 0 ? -1: state[state[state_index].prv].len);
		printf(", matched_len: %d", matched_len);
		putchar('\n');*/
	}
	
	// Find all cyclic shifts of a string
	// Call only after build()
	int process_query(char *c, int query){
		int s_len = strlen(c);
		//printf("query: %s\n", c);
		// Find initial string
		int state_index = 0;
		int cur_len = 0;
		REP(i, 0, s_len) {
			char sym = st_helper.sym_ind[c[i]];
			/*if (state[state_index].to[sym] == -1){
				return false;
			} else {
				state_index = state[state_index].to[sym];
			}*/
			while(state_index > 0 && state[state_index].to[sym] == -1) {
				state_index = state[state_index].prv;
				cur_len = state[state_index].len;
			}
			if (state[state_index].to[sym] != -1) {
				state_index = state[state_index].to[sym];
				cur_len++;
			}
			print_state(i, state_index, cur_len);
		}
		// Find all cyclic shifts
		int ans = 0;
		REP(i, 0, s_len) {
			char sym = st_helper.sym_ind[c[i]];
			while(state_index > 0 && state[state_index].to[sym] == -1) {
				state_index = state[state_index].prv;
				cur_len = state[state_index].len;
			}
			print_state(i, state_index, cur_len);
			if (state[state_index].to[sym] != -1) {
				state_index = state[state_index].to[sym];
				cur_len++;
			}
			print_state(i, state_index, cur_len);
			if (cur_len > s_len) {
				if (state[state[state_index].prv].len >= s_len) {
					state_index = state[state_index].prv;
				}
				cur_len = s_len;
			}
			print_state(i, state_index, cur_len);
			if (cur_len == s_len && query_index[state_index] != query) {
				query_index[state_index] = query;
				ans += state[state_index].cnt;
			}
		}
		return ans;
	}
};

suffix_automaton sa;

char s[MAXLEN];

void solve(){
	scanf("%s", &sa.s[0]);
	sa.len = strlen(sa.s);
	sa.build();
	int q;
	scanf("%d", &q);
	REPN(i, 1, q) {
		scanf("%s", &s[0]);
		printf("%d\n", sa.process_query(s, i));
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}