#include <bits/stdc++.h>
using namespace std;


#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXTOTALLEN = 1e6 + 5;

// Alphabet size
const int MAXSZ = 26;

// Struct for node
struct node {
	int nxt[MAXSZ];
	int prv;
	bool is_leaf;
	int go[MAXSZ];
	int link;
	int prv_ch;
	int pref_len;

	void clear(){
		for(int i = 0; i < MAXSZ; i++){
			nxt[i] = -1;
			go[i] = -1;
		}
		pref_len = 0; // !
		prv = -1;
		link = -1;
		is_leaf = false;
		prv_ch = -1;
	}
};

vi g[MAXTOTALLEN];

struct trie {
	node tt[MAXTOTALLEN];
	int n;
	int used[MAXTOTALLEN];
	queue<int> qq;

	void init(){
		tt[0].clear();
		n = 1;
	}
	void add_string(string s){
		int cur_ind = 0;
		for(int i = 0; i < (int)s.length(); i++){
			int let = s[i];
			if (tt[cur_ind].nxt[let] == -1){
				tt[n].clear();
				tt[n].prv = cur_ind;
				tt[n].prv_ch = let;
				tt[n].pref_len = tt[cur_ind].pref_len + 1; // !
				dout << n << " " << (char)('a' + s[i]) << endl;
				tt[cur_ind].nxt[let] = n++;
			}
			cur_ind = tt[cur_ind].nxt[let];
		}
		tt[cur_ind].is_leaf = true;
	}
	void bfs(){
		for(int i = 0; i < n; i++){
			used[i] = 0;
		}
		used[0] = 1;
		while(!qq.empty()){
			qq.pop();
		}
		qq.push(0);
		dout << "#\n";
		while(!qq.empty()){
			int cur_ind = qq.front();
			qq.pop();

			if (cur_ind == 0 || tt[cur_ind].prv == 0){
				tt[cur_ind].link = 0;
			} else {
				int prv = tt[cur_ind].prv;
				tt[cur_ind].link = tt[tt[prv].link].go[tt[cur_ind].prv_ch];
			}

			for(int i = 0; i < MAXSZ; i++){
				int to = tt[cur_ind].nxt[i];
				if (to != -1){
					tt[cur_ind].go[i] = to;
					used[to] = 1;
					qq.push(to);
				} else {
					if (cur_ind == 0){
						tt[cur_ind].go[i] = 0;
					} else {
						tt[cur_ind].go[i] = tt[tt[cur_ind].link].go[i];
					}
				}
			}
		}

		for(int i = 0; i < n; i++){
			used[i] = 0;
		}
		used[0] = 1;
		while(!qq.empty()){
			qq.pop();
		}
		qq.push(0);
		dout << "#\n";
		while(!qq.empty()){
			int cur_ind = qq.front();
			qq.pop();

			for(int i = 0; i < MAXSZ; i++){
				int to = tt[cur_ind].nxt[i];
				if (to != -1){
                    if(!cur_ind && tt[to].pref_len != 1 + tt[tt[to].link].pref_len){
                        g[cur_ind].pb(to);
                        g[to].pb(cur_ind);
                        dout << to << " " << cur_ind << endl;
                    }
					tt[cur_ind].go[i] = to;
					used[to] = 1;
					qq.push(to);
				} else {
					if (cur_ind == 0){
						tt[cur_ind].go[i] = 0;
					} else {
					    if(tt[tt[cur_ind].link].pref_len == tt[cur_ind].pref_len - 1){
                            g[cur_ind].pb(tt[cur_ind].link);
                            g[tt[cur_ind].link].pb(cur_ind);
					    }
						tt[cur_ind].go[i] = tt[tt[cur_ind].link].go[i];
					}
				}
			}
		}
	}
};

trie tr;
char s[MAXTOTALLEN];
bool used_dp[MAXTOTALLEN];
ll dp[MAXTOTALLEN][2];
pii root[MAXTOTALLEN];

void dfs_dp(int v){
    used_dp[v] = 1;
    dp[v][1] = 1;
    dp[v][0] = 0;
    for(int i = 0; i < (int)g[v].size(); i++){
        int to = g[v][i];
        if(used_dp[to]) continue;
        dfs_dp(to);
        dp[v][1] += dp[to][0];
        dp[v][0] += max(dp[to][0], dp[to][1]);
    }
}

void solve(){
    tr.init();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        int len = strlen(s);
        string str = s;
        for(int j = 0; j < len; j++){
            str[j] -= 'a';
        }
        tr.add_string(str);
    }
    tr.bfs();
    ll ans = 0;
    for(int i = 0; i < tr.n; i++){
        root[i] = mp(tr.tt[i].pref_len, i);
    }
    sort(root, root + tr.n);
    for(int j = 0; j < tr.n; j++){
        int i = root[j].second;
        if(used_dp[i]) continue;
        dfs_dp(i);
        if(i) ans += max(dp[i][0], dp[i][1]);
        else ans += dp[i][0];
    }
    printf("%I64d\n", ans);


    for(int i = 0; i <= tr.n; i++){
        used_dp[i] = 0;
        dp[i][0] = dp[i][1] = 0;
        g[i].clear();
    }
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}