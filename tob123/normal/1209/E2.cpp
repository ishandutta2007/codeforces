#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, M;
vector<vector<int>> A;
int best[1<<12];
int bi[12][1<<12];
vector<int> bitm[1<<12];
vector<int> G[1<<12];
bool vis[1<<12];

void dfs(int cur, int m){
	bitm[m].push_back(cur);
	vis[cur] = true;
	for(int x : G[cur]){
		if(!vis[x]){
			dfs(x, m);
		}
	}
}

int main(){
	cin >> T;

	for(int i=0; i<(1<<12); i++){
		for(int r=0; r<12; r++){
			int x = i | (1<<r);
			if(x != i){
				G[x].push_back(i);
			}
		}
	}
	for(int i=0; i<(1<<12); i++){
		for(int x : G[i]){
			dfs(x, i);
		}
		for(int x : bitm[i]){
			vis[x] = false;
		}
	}

	while(T--){
		cin >> N >> M;
		A.resize(N);
		for(int i=0; i<N; i++){
			A[i].resize(M);
			for(int j=0; j<M; j++){
				cin >> A[i][j];
			}
		}
		vector<pii> V;
		for(int i=0; i<M; i++){
			int ma = 0;
			for(int j=0; j<N; j++){
				ma = max(ma, A[j][i]);
			}
			V.push_back({ma, i});
		}
		sort(V.rbegin(), V.rend());
		
		//calc bi
		for(int i=0; i<min(N, M); i++){
			for(int m=0; m<(1<<N); m++){
				bi[i][m] = 0;
				for(int j=0; j<N; j++){
					if(m & (1<<j)){
						bi[i][m] += A[j][V[i].second];
					}
				}
			}
			for(int r=0; r<N; r++){
				for(int m=0; m<(1<<N); m++){
					bi[i][m] = max(bi[i][m], bi[i][(m>>1)+((m&1)<<(N-1))]);
				}
			}
		}
		for(int j=0; j<(1<<N); j++){
			best[j] = bi[0][j];
		}
		for(int i=1; i<min(N, M); i++){
			for(int m=(1<<N)-1; m>=0; m--){
				for(int k : bitm[m]){
					best[m] = max(best[m], best[m^k]+bi[i][k]);
				}
			}
		}
		cout << best[(1<<N)-1] << endl;
	}

  return 0;
}