#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	cat sum = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	if(sum == 1) {
		cout << "-1\n";
		return 0;
	}
	vector<cat> P;
	for(cat i = 2; i*i <= sum; i++) if(sum%i == 0) {
		P.push_back(i);
		while(sum%i == 0) sum /= i;
	}
	if(sum > 1) P.push_back(sum);
	cat ans = -1;
	for(auto p : P) {
		cat cur = sum = 0;
		vector<cat> B(N);
		for(int i = 0; i < N; i++) {
			B[i] = A[i] % p;
			sum += B[i];
		}
		int l = 0;
		for(cat i = 0; i < sum/p; i++) {
			cat rem = (p+1)/2;
			while(rem) {
				while(B[l] == 0) l++;
				cat x = min(B[l], rem);
				B[l] -= x;
				rem -= x;
				cur -= x * l;
			}
			cur += (p+1)/2 * l;
			cur -= p/2 * l;
			rem = p/2;
			while(rem) {
				while(B[l] == 0) l++;
				cat x = min(B[l], rem);
				B[l] -= x;
				rem -= x;
				cur += x * l;
			}
		}
		ans = (ans != -1) ? min(ans, cur) : cur;
	}
	cout << ans << "\n";
}