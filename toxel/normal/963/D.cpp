#include<bits/stdc++.h>

const int MAXNODE = 100010;
const int N = MAXNODE;
const int DICSIZE = 26;

int go[MAXNODE][DICSIZE], fail[MAXNODE], last[MAXNODE];
int id[MAXNODE];
int sz, root;

int newnode(){
	int ret = ++ sz;
	memset(go[ret], 0, sizeof(go[ret]));
	fail[ret] = root;
	last[ret] = root;
	//f[ret] = 0;
	return ret;
}

void init(){
	root = 0;
	sz = 0;
	root = newnode();
}

void insert(char *str, int v){
	int n = strlen(str);
	int p = root;
	for(int i = 0; i < n; ++ i){
		int c = str[i] - 'a';
		if(!go[p][c]){
			go[p][c] = newnode();
		}
		p = go[p][c];
	}
	id[p] = v;
}

void makefail(){
	std::queue<int> queue;
	queue.push(root);
	while(!queue.empty()){
		int p = queue.front(); queue.pop();
		for(int i = 0; i < DICSIZE; ++ i){
			if(go[p][i]){
				fail[go[p][i]] = fail[p] ? go[fail[p]][i] : root;
				last[go[p][i]] = id[fail[go[p][i]]] ? fail[go[p][i]] : last[fail[go[p][i]]];
				int q = go[p][i];
				//f[q] |= f[fail[q]];
				queue.push(q);
			}
			else{
				go[p][i] = p == root ? root : go[fail[p]][i];
			}
		}
	}
}

char s[N];
std::vector <int> vec[N];
char q[N];
char tmp[N];
int k[N], length[N];

int main(){
	//freopen("data.txt", "r", stdin);
	fgets(s, N, stdin);
	fgets(tmp, N, stdin);
	int n;
	sscanf(tmp, "%d", &n);
	init();
	for (int i = 1; i <= n; ++ i){
		fgets(tmp, N, stdin);
		sscanf(tmp, "%d%s", &k[i], q);
		insert(q, i);
		length[i] = strlen(q);
	}
	makefail();
	int p = 1, len = strlen(s);
	s[-- len] = '\0';
	for (int i = 0; i < len; ++ i){
		p = go[p][s[i] - 'a'];
		int t = p;
		while (t != 0){
			if (id[t]){
				vec[id[t]].push_back(i);
			}
			t = last[t];
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (vec[i].size() < k[i]){
			puts("-1");
			continue;
		}
		int ans = INT_MAX;
		for (int j = 0, sz = vec[i].size(); j + k[i] - 1 < sz; ++ j){
			ans = std::min(ans, vec[i][j + k[i] - 1] - vec[i][j] + length[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}