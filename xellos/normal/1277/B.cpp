#include <iostream>
#include <set>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		set<int> A;
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			A.insert(a);
		}
		int ans = 0;
		while(!A.empty()) {
			int a = *A.rbegin();
			A.erase(--A.end());
			if(a%2 == 0) A.insert(a/2), ans++;
		}
		cout << ans << "\n";
	}
}