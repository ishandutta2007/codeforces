#include<bits/stdc++.h>

const int N = 510;
const int moder = 1e9 + 7;

std::vector <int> e[N];

char s[N];
int type[N];
int req[N];

int process(int l, int r){
    if (l == r){
        type[l] = 0;
        return l;
    }
    int cnt = 0, root;
    for (int i = l; i <= r; ++ i){
        cnt += s[i] == '(';
        cnt -= s[i] == ')';
        if (!cnt){
            root = i + 1;
            break;
        }
    }
    type[root] = 1;
    e[root].push_back(process(l + 1, root - 2));
    e[root].push_back(process(root + 2, r - 1));
    return root;
}

int dp[N][1 << 16];

void update(int *dp, char ch){
    int x = 0;
    int type = ch >= 'a' && ch <= 'z';
    ch = tolower(ch);
    for (int i = 0; i < 16; ++ i){
        x |= (type ^ (i >> ch - 'a' & 1)) << i;
    }
    ++ dp[x];
}

void FWT_AND(int *a, int length, int type){
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1);
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < length; j += 1 << i){
			for (int k = j, szk = 1 << i - 1; k < j + szk; ++ k){
				a[k] = (a[k] + 1ll * type * a[k + szk] + moder) % moder;
			}
		}
	}
}

void FWT_OR(int *a, int length, int type){
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1);
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < length; j += 1 << i){
			for (int k = j, szk = 1 << i - 1; k < j + szk; ++ k){
				a[k + szk] = (a[k + szk] + 1ll * type * a[k] + moder) % moder;
			}
		}
	}
}

int tmp[1 << 16], tmp1[1 << 16], tmp2[1 << 16];

void update(int *dp, int *dp1, int *dp2, char ch){
    memcpy(tmp1, dp1, sizeof(tmp1));
    memcpy(tmp2, dp2, sizeof(tmp2));
    if (ch == '|'){
        FWT_OR(tmp1, 1 << 16, 1);
        FWT_OR(tmp2, 1 << 16, 1);
        for (int i = 0; i < 1 << 16; ++ i){
            tmp[i] = 1ll * tmp1[i] * tmp2[i] % moder;
        }
        FWT_OR(tmp, 1 << 16, -1);
    }
    else{
        FWT_AND(tmp1, 1 << 16, 1);
        FWT_AND(tmp2, 1 << 16, 1);
        for (int i = 0; i < 1 << 16; ++ i){
            tmp[i] = 1ll * tmp1[i] * tmp2[i] % moder;
        }
        FWT_AND(tmp, 1 << 16, -1);
    }
    for (int i = 0; i < 1 << 16; ++ i){
        dp[i] += tmp[i];
        dp[i] -= dp[i] >= moder ? moder : 0;
    }
}

void dfs(int u){
    for (auto v : e[u]){
        dfs(v);
    }
    if (type[u] == 0){
        if (s[u] == '?'){
            for (int i = 'A'; i <= 'D'; ++ i){
                update(dp[u], i);
                update(dp[u], i - 'A' + 'a');
            }
        }
        else{
            update(dp[u], s[u]);
        }
    }
    else{
        if (s[u] == '?'){
            update(dp[u], dp[e[u][0]], dp[e[u][1]], '|');
            update(dp[u], dp[e[u][0]], dp[e[u][1]], '&');
        }
        else{
            update(dp[u], dp[e[u][0]], dp[e[u][1]], s[u]);
        }
    }
}

int main(){
    scanf("%s", s);
    int n = strlen(s);
    int root = process(0, n - 1);
    dfs(root);
    scanf("%d", &n);
    memset(req, -1, sizeof(req));
    for (int i = 0; i < n; ++ i){
        int x = 0;
        for (int j = 0, y; j < 4; ++ j){
            scanf("%d", &y);
            x |= y << j;
        }
        scanf("%d", &req[x]);
    }
    int ans = 0;
    for (int i = 0; i < 1 << 16; ++ i){
        bool flag = true;
        for (int j = 0; j < 16; ++ j){
            if (~req[j] && (i >> j & 1) != req[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            ans += dp[root][i];
            ans -= ans >= moder ? moder : 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}