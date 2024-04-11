#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 2e5 + 5;

int T, N, M;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for(int t = 0; t < T; ++t){
		cin >> N;
		vector<int> C;
		C.resize(N);
		for(int i = 0; i < N; ++i){
			int a; cin >> a; a--;
			C[a]++;
		}
		vector<int> K;
		int j = 0;
		int minV = N+2;
		for(int i = 0; i < N; ++i){
			if(C[i] != 0){
				K.push_back(C[i]);
				j++;
				minV = min(minV, C[i]);
			}
		}
		M = j;
		for(ll s = minV + 1; s >= 1; --s){
			ll c = 0;
			for(int i = 0; i < M; ++i){
				if((s-1) * ((K[i]+s-1)/s) > K[i])
					goto AZ;
			}
			for(int i = 0; i < M; ++i){
				c += (K[i]+s-1)/s;
			}
			cout << c << "\n";
			break;
			AZ:;
		}
	}

	return 0;
}