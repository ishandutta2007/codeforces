#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 5001;

int N, M;
vector<pii> I[n], O[n];
int in[n];
int col[n];

int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		O[u].push_back({v, i});
		I[v].push_back({u, i});
	}
	int cnt = 0;
	queue<int> Q;
	for(int i=0; i<N; i++){
		in[i] = sz(I[i]);
		if(in[i] == 0)
			Q.push(i);
	}
	while(!Q.empty()){
		cnt++;
		int cur = Q.front();
		Q.pop();
		for(auto p : O[cur]){
			in[p.first]--;
			if(in[p.first] == 0)
				Q.push(p.first);
		}
	}
	if(cnt == N){
		for(int i=0; i<M; i++){
			col[i] = 1;
		}
		cout << 1 << endl;
	}
	else{
		for(int i=0; i<N; i++){
			for(auto p : I[i]){
				if(col[p.second] == 0)
					col[p.second] = 1;
			}
			for(auto p : O[i]){
				if(col[p.second] == 0)
					col[p.second] = 2;
			}
		}
		cout << 2 << endl;
	}

	for(int i=0; i<M; i++){
		cout << col[i] << " ";
	}
	cout << endl;

  return 0;
}