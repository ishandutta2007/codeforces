#include<bits/stdc++.h>
using namespace std;
 
int dist(int x, int b, int c, int d) {
	return abs(x-c) + abs(b-d);
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		int64_t N, K;
		cin >> N >> K;
		vector<array<int, 2>> V(N);
		for(auto &e: V) cin >> e[0] >> e[1];
		bool ok=0;
		for(int i =0; i < N; i++) {
			int c=0;
			for(int j=0; j < N; j++) {
				if(dist(V[i][0], V[i][1], V[j][0], V[j][1]) <= K) {
					c++;
				}
			}
			if(c==N) ok=1;
		}
		cout << (ok?"1":"-1") << '\n';
 
	}
}