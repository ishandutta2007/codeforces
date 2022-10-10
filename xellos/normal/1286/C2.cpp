#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

vector< pair<char, char> > get_pairs(vector< vector<string> > & S) {
	int N = S.size()-1;
	vector< pair<char, char> > ret;
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for(auto c : S[N][0]) cnt[c-'a']++;
	for(int i = 0; i < (N+1)/2-1; i++) {
		int sums[26];
		memset(sums, 0, sizeof(sums));
		for(auto s : S[i+2]) for(auto c : s) sums[c-'a']++;
		for(int j = 0; j < i; j++) {
			sums[ret[j].ff-'a'] -= j+1;
			sums[ret[j].ss-'a'] -= j+1;
		}
		for(int j = 0; j < 26; j++) sums[j] -= (i+2) * cnt[j];
		pair<char, char> p = {0, 0};
		for(int j = 0; j < 26; j++) while(sums[j]) {
			sums[j]++;
			if(!p.ff) p.ff = j+'a';
			else p.ss = j+'a';
		}
		cnt[p.ff-'a']--, cnt[p.ss-'a']--;
		ret.push_back(p);
	}
	pair<char, char> p = {0, 0};
	for(int j = 0; j < 26; j++) while(cnt[j]) {
		cnt[j]--;
		if(!p.ff) p.ff = j+'a';
		else p.ss = j+'a';
	}
	ret.push_back(p);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<string> > S[3];
	cout << "? 1 " << N << endl;
	S[0].resize(N+1);
	for(int i = 1; i <= N; i++) for(int j = 0; j < i; j++) {
		string s;
		cin >> s;
		sort(begin(s), end(s));
		S[0][s.length()].push_back(s);
	}
	if(N == 1) {
		cout << "! " << S[0][N][0] << "\n";
		return 0;
	}
	cout << "? 1 " << N/2 << endl;
	S[1].resize(N/2+1);
	for(int i = 1; i <= N/2; i++) for(int j = 0; j < i; j++) {
		string s;
		cin >> s;
		sort(begin(s), end(s));
		S[1][s.length()].push_back(s);
	}
	int l = (N/2)+(N%2);
	cout << "? " << l << " " << N << endl;
	S[2].resize(N-l+2);
	for(int i = 1; i <= N-l+1; i++) for(int j = 0; j < i; j++) {
		string s;
		cin >> s;
		sort(begin(s), end(s));
		S[2][s.length()].push_back(s);
	}
	vector< pair<char, char> > pairs[3];
	int c_mid = 0;
	for(int k = 0; k < 3; k++) {
		pairs[k] = get_pairs(S[k]);
		for(auto s : S[k][1]) c_mid += s[0] * (k ? 1 : -1);
	}
	string ans;
	for(int i = 0; i < N; i++) ans += '.';
	queue<int> q_pos;
	if(N%2 == 0) {
		ans[N/2-1] = c_mid;
		q_pos.push(N/2-1);
	}
	for(int i = 0; i < (int)pairs[0].size(); i++) if(!pairs[0][i].ss) {
		ans[i] = pairs[0][i].ff;
		q_pos.push(i);
	}
	for(int i = 0; i < (int)pairs[1].size(); i++) if(!pairs[1][i].ss) {
		ans[i] = pairs[1][i].ff;
		q_pos.push(i);
	}
	for(int i = 0; i < (int)pairs[2].size(); i++) if(!pairs[2][i].ss) {
		ans[l-1+i] = pairs[2][i].ff;
		q_pos.push(l-1+i);
	}
	while(!q_pos.empty()) {
		int pos = q_pos.front();
		q_pos.pop();
		if(ans[N-1-pos] == '.') {
			int id = min(pos, N-1-pos);
			ans[N-1-pos] = pairs[0][id].ff + pairs[0][id].ss - ans[pos];
			q_pos.push(N-1-pos);
		}
		if(pos < N/2 && ans[N/2-1-pos] == '.') {
			int id = min(pos, N/2-1-pos);
			ans[N/2-1-pos] = pairs[1][id].ff + pairs[1][id].ss - ans[pos];
			q_pos.push(N/2-1-pos);
		}
		if(pos >= l-1 && ans[N-1-(pos-l+1)] == '.') {
			int id = min(pos-l+1, N-1-pos);
			ans[N-1-(pos-l+1)] = pairs[2][id].ff + pairs[2][id].ss - ans[pos];
			q_pos.push(N-1-(pos-l+1));
		}
	}
	cout << "! " << ans << endl;
	return 0;
}

// look at my code
// my code is amazing