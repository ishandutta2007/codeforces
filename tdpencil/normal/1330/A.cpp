#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;
	while(T--) {
        int N, X;
        cin >> N >> X;
        vector<int> A(N);
        set<int> D;
        for(int i = 1; i <= 300; i++)
            D.insert(i);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        for(int i = 0; i < N; i++) {
            D.erase(A[i]);
        }
        for(int i = 0; i < X; i++) {
            D.erase(*D.begin());
        }
        cout << *D.begin()  - 1 << "\n";
	}
}