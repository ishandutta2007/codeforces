#include <vector>
#include <iostream>
using namespace std;

int next(vector<int>& v, int i) {
	return v[i];
}

int main() {
	int N;
	cin >> N;
	
	vector<int> v(N+1);
	for (int i = 1; i <= N; i++) {
		int fi;
		cin >> fi;
		v[i] = fi;
	}

	bool found = false;
	for (int i = 1; i <= N; i++) {
		if (next(v, next(v, next(v,i))) == i) {
			cout << "YES\n";
			found = true;
			break;
		}
	}
	if (!found) {
		cout  << "NO\n";
	}	
}