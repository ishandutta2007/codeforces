#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> vec(1, 0);
	for(int i = 0; vec.back() < 1e9; i++){
		vec.push_back(vec.back() + (i - i / 3) * 2);
	}
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		cout << lower_bound(vec.begin(), vec.end(), n) - vec.begin() << "\n";
	}
}