using namespace std;

#include <iostream>

#define MAXN 55

// if N is odd, always best to take 0
// if N is even, always take 1

int N,a[MAXN];

void solve() {
	cin >> N;
	pair<long long,int> uwu = {1e18,N + 1};
	for(int i = 1;i <= N;++i) {
		cin >> a[i];
		uwu = min(uwu,{a[i],i});
	}
	if(N & 1) {
		cout << "Mike" << endl;
	}else{
		long long owo = (uwu.first) * N + uwu.second;
		if(owo & 1) {
			cout << "Joe" << endl;
		}else{
			cout << "Mike" << endl;
		}
	}
	return;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}