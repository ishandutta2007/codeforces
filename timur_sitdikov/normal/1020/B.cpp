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
		vector<bool> b(N+1, false);
		
		int current = i;
		while(! b[next(v,current)] ) {
			b[current] = true;
			current = next(v, current);
		}
		cout << next(v, current) << " ";
	}	
}