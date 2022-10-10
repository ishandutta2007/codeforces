#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

using cat = long long;

struct fin {
	vector<int> T;
	fin(int N) : T(N+1, 0) {}

	int lastone(int x) { return x & (x ^ (x-1)); }

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}
};

struct bigint {
	short d[24];
	bigint() { for(int i = 0; i < 24; i++) d[i] = 0; }

	bigint & operator+=(cat c) {
		for(int i = 0; i < 23 && (c || d[i] >= 10); i++, c /= 10) {
			d[i] += c % 10;
			d[i+1] += d[i] / 10;
			d[i] %= 10;
		}
		return *this;
	}

	string to_str() {
		string ret;
		int i = 23;
		while(i && !d[i]) i--;
		while(true) {
			ret += ('0'+d[i]);
			if(!i) break;
			i--;
		}
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> S(N), prev(N+1, 0), prev_difc(N+1, 0);
	vector< pair<int, int> > W;
	fin F(N+10);
	cat cur = 0, a26 = 0, a30 = 0;
	bigint ans;
	for(int i = 0; i < N; i++) {
		string s;
		int w;
		cin >> s >> w;
		int c = (s[0]-'a'+a26)%26;
		S[i] = c;
		if(S[i] != S[prev[i]]) prev_difc[i] = prev[i];
		else if(prev[i]) prev_difc[i] = prev_difc[prev[i]];
		if(i >= 1) {
			for(prev[i+1] = prev[i]; prev[i+1] && S[prev[i+1]] != c; prev[i+1] = prev[prev[i+1]]) {
				pair<int, int> p = {i-prev[i+1]+1, 0};
				cur -= lower_bound(begin(W), end(W), p)->second;
				F.put(i-prev[i+1]+1, -1);
			}
			if(S[prev[i+1]] == c) {
				int v = prev[i+1];
				prev[i+1]++;
				while(v) {
					v = prev_difc[v];
					while(v && S[v] != c) {
						pair<int, int> p = {i-v+1, 0};
						cur -= lower_bound(begin(W), end(W), p)->second;
						F.put(i-v+1, -1);
						v = prev[v];
					}
				}
			}
		}
		w ^= a30 & ((1LL<<30)-1);
		while(!W.empty() && W.back().second >= w) {
			int n_old = F.get(W.back().first);
			cat d = w-W.back().second;
			W.pop_back();
			int n_new = W.empty() ? 0 : F.get(W.back().first);
			cur += d * (n_old-n_new);
		}
		W.push_back({i+1, w});
		if(i >= 1 && S[0] == c) {
			F.put(i+1, 1);
			cur += w;
		}
		a26 += (cur + W[0].second) % 26;
		a30 += (cur + W[0].second) & ((1LL<<30)-1);
		ans += cur + W[0].second;
		cout << ans.to_str() << "\n";
	}
}