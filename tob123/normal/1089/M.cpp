#include <bits/stdc++.h>
using namespace std;
const int n = 10;

int N;
bool M[n][n], vis[n], inS[n];
int low[n], num[n], cmpA[n];
int C = 0, T = 0;
vector<int> cmp[n];
stack<int> S;
vector<int> topOrd;
set<int> adj[n];
int inc[n], topNum[n];

char m[50][50][50];

void DFS(int i){
	vis[i] = true;
	inS[i] = true;
	low[i] = num[i] =T;
	T++;
	S.push(i);
	for(int j = 0; j < N; ++j){
		if(M[i][j]){
			if(vis[j]){
				if(inS[j]){
					//back-edge
					low[i] = min(low[i], num[j]);
				}else{
					//cross-edge
				}
			}else{
				DFS(j);
				low[i] = min(low[i], low[j]);
			}
		}
	}
	if(num[i] == low[i]){
		int v;
		do{
			v = S.top();
			S.pop();
			cmp[C].push_back(v);
			cmpA[v] = C;
			inS[v] = false;
		}while(v != i);
		C++;
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> M[i][j];
		}
	}
	for(int i = 0; i < N; ++i){
		if(!vis[i])
			DFS(i);
	}
	for(int c = 0; c < C; ++c){
		for(int v : cmp[c]){
			for(int k = 0; k < N; ++k){
				if(M[v][k] && cmpA[v] != cmpA[k]){
					adj[c].insert(cmpA[k]);
				}
			}
		}
	}
	for(int c = 0; c < C; ++c){
		for(int j : adj[c]){
			inc[j]++;
		}
	}
	queue<int> Q;
	for(int c = 0; c < C; ++c){
		if(inc[c] == 0){
			Q.push(c);
		}
	}
	int num = 0;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		topNum[cur] = num++;
		for(int j : adj[cur]){
			inc[j]--;
			if(inc[j] == 0){
				Q.push(j);
			}
		}
	}
	for(int l = 0; l < C; ++l){
		//boden
	}
	for(int c =0; c < C; ++c){
		int lay = (C-topNum[c]-1) * 2 + 1;
		//boden
		for(int i = 0; i < 50; ++i){
			for(int j = 0; j < 50; ++j){
				char cr = '#';
				if(j == 0 && i%2 == 0 && i != 2*c)
					cr = '.';
				m[lay-1][i][j] = cr;
			}
			if(i % 2 == 1){
				m[lay][i][0] = '#';
			}else{
				int to = i/2;
				if(!(adj[c].count(to) == 1) && i != 2*c)	
					m[lay][i][1] = '#';
			}	
		}
		for(int i = 0; i < cmp[c].size(); ++i){
			int x = cmp[c][i];
			m[lay][i][2] = ('1' + x);
		}
	}
	int h = C*2;
	cout <<50 << " 3 " << h << "\n";
	int s2 = 50;
	for(int i = h-1; i >=0; --i){
		for(int j =  0; j < 3; ++j){
			for(int k = 0; k < s2; ++k){
				if(m[i][k][j] == 0)
					cout << '.';
				else cout << m[i][k][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}