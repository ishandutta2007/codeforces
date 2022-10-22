#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
	while (T--){
		int N; cin >> N;
		for (int i = 0; i < N; ++i){
			int x; cin >> x;
		}
		N = 10 - N;
		cout << 6 * N * (N-1) / 2 << '\n';
	}
}