#include<bits/stdc++.h>

const int MAXNODE = 50010;
const int N = MAXNODE;
const int DICSIZE = 10;
const int MAXLEN = 60;
typedef long long ll;
const int moder = 1e9 + 7;

int go[MAXNODE][DICSIZE], fail[MAXNODE], last[MAXNODE];
ll dp[MAXNODE][MAXLEN];
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

void insert(char *str, int n, int v){
	int p = root;
	for(int i = 0; i < n; ++ i){
		int c = str[i] - '0';
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

char s[N], x[N], y[N];

ll solve(char *x, int d){
    int tmp = root;
    int ans = 0;
    for (int i = 0; i < d; ++ i){
        ans = (10ll * ans + x[i] - '0') % moder;
    }
    for (int i = 0; i < d; ++ i){
        for (int j = !i; j < x[i] - '0'; ++ j){
            int p = go[tmp][j];
            ans -= dp[p][d - i - 1];
            ans += ans < 0 ? moder : 0;
        }
        if (x[i] < '0' + 10){
            tmp = go[tmp][x[i] - '0'];
            if (id[tmp]) break;
        }
    }
    return ans;
}

int main(){
    init();
    scanf("%s%s%s", s, x, y);
    int n = strlen(s);
    int d = strlen(x);
    for (int i = 0; i <= n - (d >> 1); ++ i){
        insert(s + i, d >> 1, i + 1);
    }
    makefail();
    for (int i = 0; i < MAXLEN; ++ i){
        for (int j = root; j < MAXNODE; ++ j){
            if (id[j]) continue;
            if (!i){
                dp[j][i] = 1;
                continue;
            }
            for (int k = 0; k < 10; ++ k){
                dp[j][i] += dp[go[j][k]][i - 1];
                dp[j][i] -= dp[j][i] >= moder ? moder : 0;
            }
        }
    }
    ++ y[d - 1];
    for (int i = d - 1; i > 0; -- i){
        if (y[i] >= '0' + 10){
            y[i] -= 10;
            ++ y[i - 1];
        }
    }
    int ans = solve(y, d) - solve(x, d);
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}