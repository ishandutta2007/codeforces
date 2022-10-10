#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;

using cat = long long;

int subs[1<<19];

void generate_subsets(int mask, int N) {
	vector<int> bits;
	for(int i = 0; i < N; i++) if((mask>>i)&1) bits.push_back(i);
	int B = bits.size();
	subs[0] = 0;
	memset(subs, 0, sizeof(int) * (1<<B));
	for(int i = 0, b = 0; i < (1<<B); i++) {
		while(i >= (1<<b)) b++;
		for(int j = b; j < B; j++) subs[i+(1<<j)] = subs[i]+(1<<bits[j]);
	}
}

int main() {
	int N;
	cin >> N;
	vector<cat> A(N), S(1<<N, 0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if(!A[i]) i--, N--;
	}
	for(int i = 0, b = 0; i < (1<<N); i++) {
		while(i >= (1<<b)) b++;
		for(int j = b; j < N; j++) S[i+(1<<j)] = S[i] + A[j];
	}
	vector<char> C(1<<N, 0);
	for(int i = 1; i < (1<<N); i++) if(__builtin_popcount(i) <= N/3) {
		int n = __builtin_popcount(i);
		generate_subsets(i, N);
		for(int j = 1; j < (1<<n)-1; j++) {
			cat dif = S[subs[j]]-S[i-subs[j]];
			if(dif < 0) dif *= -1;
			if(dif < n && (dif-n)%2 != 0) {
				C[i] = 1;
				break;
			}
		}
	}
	for(int i = 0; i < (1<<N); i++) if(C[i]) for(int j = 0; j < N; j++)
		if(!((i>>j)&1)) C[i+(1<<j)] |= 2;
	vector< pair<cat, int> > SI((2<<N)-2);
	for(int i = 1; i < (1<<N); i++) {
		int n = __builtin_popcount(i);
		SI[2*(i-1)] = {S[i]-n+1, -i};
		SI[2*(i-1)+1] = {S[i]+n, i};
	}
	sort(begin(SI), end(SI));
	unordered_set<int> S_open[2];
	vector<char> is_open[2] = {vector<char>(1<<N, 0), vector<char>(1<<N, 0)};
	for(int i = 0; i < (int)SI.size(); i++) {
		int p = (SI[i].first%2 != 0);
		int id = SI[i].second;
		if(id < 0) {
			id *= -1;
			if(!C[id]) {
				int n = N-__builtin_popcount(id);
				if((1<<n) >= 4*(int)S_open[p^1].size())
					for(auto s : S_open[p^1]) C[id|s] |= !(id&s);
				else {
					generate_subsets((1<<N)-1-id, N);
					for(int j = 0; j < (1<<n); j++) C[subs[j]|id] |= is_open[p^1][subs[j]];
				}
			}
			if(!C[id]) {
				S_open[p].insert(id);
				is_open[p][id] = 1;
			}
		}
		else {
			p ^= 1;
			if(is_open[p][id]) {
				S_open[p].erase(id);
				is_open[p][id] = 0;
			}
		}
	}
	for(int i = 0; i < (1<<N); i++) if(C[i]) for(int j = 0; j < N; j++)
		if(!((i>>j)&1)) C[i+(1<<j)] |= 2;
	vector<int> CV;
	for(int i = 0; i < (1<<N); i++) if(C[i] == 1) CV.push_back(i);
	vector<char> dp(1<<N, 0);
	for(int i = 0; i < (1<<N); i++) for(auto s : CV)
		if(!(i&s) && dp[i+s] <= dp[i]) dp[i+s] = dp[i]+1;
	int ans = N;
	for(int i = 0; i < (1<<N); i++) ans = min(ans, N-dp[i]);
	cout << ans << "\n";
}