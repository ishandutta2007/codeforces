#include <bits/stdc++.h>

#define MAXN ((1010) << 1)  

const int N = 1010;

struct _2sat{   //for 2-sat MAXN is two times large
	int top, bcnt, num, n;
	int dfn[MAXN], low[MAXN], stack[MAXN], opp[MAXN];
	int belong[MAXN], col[MAXN], deg[MAXN];
	bool ans[MAXN], instack[MAXN];
	std::vector<int> vec[MAXN], _vec[MAXN];
	
	_2sat(int n):n(n){
	    memset(dfn, 0, sizeof(dfn));
	    memset(low, 0, sizeof(low));
	    memset(opp, 0, sizeof(opp));
	    memset(instack, 0, sizeof(instack));
	    memset(stack, 0, sizeof(stack));
	    memset(belong, 0, sizeof(belong));
	    memset(col, 0, sizeof(col));
	    memset(deg, 0, sizeof(deg));
	    memset(ans, 0, sizeof(ans));
	}
	
	void tarjan(int u){
		dfn[u] = low[u] = ++ num;
		stack[++ top] = u;
		instack[u] = true;
		for(auto v : vec[u]){
			if(!dfn[v]){
				tarjan(v);
				if(low[v] < low[u]) low[u] = low[v];
			}
			else{
				if(instack[v] && dfn[v] < low[u]) low[u] = dfn[v];
			}
		}
		if(dfn[u] == low[u]){
			bcnt ++;
			int v;
			do{
				v = stack[top --];
				instack[v] = false;
				belong[v] = bcnt;
			}while(v != u);
		}
	}
	
	void insert(int u, int v){
		vec[u].push_back(v);
	}
	
	bool solve(){ //tarjan + topsort
	    top = bcnt = num = 0;
	    
	    for(int i = 1; i <= n * 2; ++ i){
	    	if(!dfn[i]){
	    		tarjan(i);
	    	}
	    }
	    
	    for(int i = 1; i <= n; ++ i){
	    	if(belong[i] == belong[i + n]) return false;
	    	opp[belong[i]] = belong[i + n];
	    	opp[belong[i + n]] = belong[i];
	    }
	    
	    
	    for(int i = 1; i <= n * 2; ++ i){
	    	for(auto j : vec[i]){
	    		if(belong[i] != belong[j]){
	    			_vec[belong[j]].push_back(belong[i]);
	    			deg[belong[i]] ++;
	    		}
	    	}
	    }
	    
	    std::queue<int> queue;
	    for(int i = 1; i <= bcnt; ++ i){
	    	if(!deg[i]){
	    		queue.push(i);
	    	}
	    }
	    
	    while(!queue.empty()){
	    	int u = queue.front();
	    	queue.pop();
	    	
	    	if(!col[u]){
	    		col[u] = 1;
	    		col[opp[u]] = -1;
	    	}
	    	
	    	for(auto v : _vec[u]){
	    		deg[v] --;
	    		if(!deg[v]){
	    			queue.push(v);
	    		}
	    	}
	    }
	    
	    for(int i = 1; i <= n * 2; ++ i){
	    	if(col[belong[i]] == 1){
	    		ans[i] = 1;
	    	}
	    }
	    return true;
	}
};

int n;
std::string str[N][2];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		std::cin >> str[i][0] >> str[i][1];
		str[i][0] = str[i][0].substr(0, 3);
		str[i][1] = str[i][0].substr(0, 2) + str[i][1][0];
	}
	_2sat sat(n);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			if (j == i){
				continue;
			}
			if (str[i][0] == str[j][0]){
				sat.insert(i, j + n);
				sat.insert(j, i + n);
				sat.insert(i + n, j + n);
				sat.insert(j, i);
			}
			if (str[i][0] == str[j][1]){
				sat.insert(i, j);
				sat.insert(j + n, i + n);
			}
			if (str[i][1] == str[j][0]){
				sat.insert(i + n, j + n);
				sat.insert(j, i);
			}
			if (str[i][1] == str[j][1]){
				sat.insert(i + n, j);
				sat.insert(j + n, i);
			}
		}
	}
	if (!sat.solve()){
		return printf("NO\n"), 0;
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++ i){
		if (sat.ans[i]){
			std::cout << str[i][0] << std::endl;
		}
		else{
			std::cout << str[i][1] << std::endl;
		}
	}
	return 0;
}