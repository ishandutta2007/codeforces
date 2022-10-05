#include<bits/stdc++.h>

const int MAXN = 201;
const int N = MAXN;

int n;

struct twoSat{   //for 2-sat MAXN is two times large
	
	int col[MAXN];
	std::vector<int> vec[MAXN << 1];
	int dfn[MAXN << 1], low[MAXN << 1], bel[MAXN << 1], ncnt, scnt;
	bool vis[MAXN << 1];
	std::stack<int> stack;
	
	void tarjan(int u){
		dfn[u] = low[u] = ++ ncnt;
		stack.push(u);
		vis[u] = true;
		for(auto v : vec[u]){
			if(!dfn[v]){
				tarjan(v);
				low[u] = std::min(low[u], low[v]);
			}
			else if(vis[v]){
				low[u] = std::min(low[u], dfn[v]);
			}
		}
		if(low[u] == dfn[u]){
			int v; ++ scnt;
			do{
				v = stack.top(); stack.pop();
				vis[v] = false;
				bel[v] = scnt;
			}while(v != u);
		}
	}
	
	void addedge(int u, int v){
		vec[u].push_back(v);
	}
	
	bool solve(){ //tarjan + topsort
	    memset(dfn, 0, sizeof(dfn));
	    memset(vis, 0, sizeof(vis));
	    ncnt = scnt = 0;
	    for(int i = 1; i <= n + n; ++ i){
		    if(!dfn[i]){
			    tarjan(i);
			}
		}
		for(int i = 1; i <= n; ++ i){
			if(bel[i] == bel[i + n]){
				return false;
			}
		}
		for(int i = 1; i <= n; ++ i){
			col[i] = (bel[i] < bel[i + n]);
		}
		
		return true;
	}
};

char type[N], s[N], tmp1[N], tmp2[N];
int a[N];
twoSat ts1, ts2;
std::set <int> set[N << 1];

void add(twoSat &ts, int tp, int sit){
    if (type[tp] == 'C'){
        ts.addedge(sit + 1, sit + 1 + n);
    }
    else{
        ts.addedge(sit + 1 + n, sit + 1);
    }
}

int main(){
    int m;
    scanf("%s%d%d", type, &n, &m);
    int l = strlen(type);
    for (int i = 0; i < m; ++ i){
        int pos1, pos2;
        scanf("%d%s%d%s", &pos1, tmp1, &pos2, tmp2);
        int u = tmp1[0] == 'C' ? pos1 + n : pos1;
        int v = tmp2[0] == 'C' ? pos2 + n : pos2;
        set[u].insert(v);
        u = tmp1[0] == 'V' ? pos1 + n : pos1;
        v = tmp2[0] == 'V' ? pos2 + n : pos2;
        set[v].insert(u);
    }
    bool flag = true;
    for (int i = 0; i < l; ++ i){
        if (type[i] != type[0]){
            flag = false;
            break;
        }
    }
    if (flag){
        for (int i = 0; i < n; ++ i){
            add(ts1, 0, i);
        }
    }
    for (int i = 0; i < N << 1; ++ i){
        for (auto u : set[i]){
            ts1.addedge(i, u);
        }
    }
    scanf("%s", s);
    if (!ts1.solve()){
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; ++ i){
        a[i] = s[i] - 'a';
    }
    for (int i = n - 1; i >= 0; -- i){
        bool cflag = true, vflag = true;
        for (int j = i == n - 1 ? a[i] : a[i] + 1; j < l; ++ j){
            if (type[j] == 'C' && !cflag || type[j] == 'V' && !vflag){
                continue;
            }
            ts2 = ts1;
            for (int k = 0; k < i; ++ k){
                add(ts2, a[k], k);
            }
            add(ts2, j, i);
            if (ts2.solve()){
                a[i] = j;
                for (int k = i + 1; k < n; ++ k){
                    cflag = true, vflag = true;
                    for (int u = 0; u < l; ++ u){
                        if (type[u] == 'C' && !cflag || type[u] == 'V' && !vflag){
                            continue;
                        }
                        ts2 = ts1;
                        for (int v = 0; v < k; ++ v){
                            add(ts2, a[v], v);
                        }
                        add(ts2, u, k);
                        if (!ts2.solve()){
                            if (type[u] == 'C'){
                                cflag = false;
                            }
                            else{
                                vflag = false;
                            }
                        }
                        else{
                            a[k] = u;
                            break;
                        }
                    }
                }
                for (int i = 0; i < n; ++ i){
                    putchar(a[i] + 'a');
                }
                putchar('\n');
                return 0;
            }
            if (type[j] == 'C'){
                cflag = false;
            }
            else{
                vflag = false;
            }
        }
    }
    puts("-1");
    return 0;
}