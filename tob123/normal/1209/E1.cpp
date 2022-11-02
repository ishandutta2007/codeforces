#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, M;
vector<vector<int>> A;

int main(){
	cin >> T;
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
		int bestSum = 0;
		for(int i=0; i<pow(N, min(N, M)); i++){
			int sum = 0;
			for(int k=0; k<N; k++){
				int mask = i;
				int b = 0;
				for(int j=0; j<min(N, M); j++){
					b = max(b, A[(mask+k)%N][V[j].second]);
					mask /= N;
				}
				sum += b;
			}
			bestSum = max(bestSum, sum);
		}
		cout << bestSum << endl;
	}

  return 0;
}