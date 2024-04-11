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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int cnt[4];
	cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
	if(cnt[0] > cnt[1]+1) {
		cout << "NO\n";
		return 0;
	}
	if(cnt[0] == cnt[1]+1) {
		if(cnt[2]+cnt[3]) {
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n0";
		for(int i = 0; i < cnt[1]; i++) cout << " 1 0";
		cout << "\n";
		return 0;
	}
	if(cnt[3] > cnt[2]+1) {
		cout << "NO\n";
		return 0;
	}
	if(cnt[3] == cnt[2]+1) {
		if(cnt[0]+cnt[1]) {
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n3";
		for(int i = 0; i < cnt[2]; i++) cout << " 2 3";
		cout << "\n";
		return 0;
	}
	int N = cnt[0]+cnt[1]+cnt[2]+cnt[3];
	vector<int> ans;
	for(int start = 0; start < 4; start++) if(cnt[start]) {
		if(!ans.empty()) continue;
		if(start == 0 || start == 3) cnt[start]--;
		// remove 10, 23
		if(cnt[1] >= cnt[0] && cnt[2] >= cnt[3]) {
			cnt[1] -= cnt[0];
			cnt[2] -= cnt[3];
			// (?03)121212
			if(cnt[1] <= cnt[2]+1 && cnt[2] <= cnt[1]+1 && cnt[1]+cnt[2]) {
				vector<int> cur;
				cur.dibs(N);
				cur.push_back((cnt[1] > cnt[2]) ? 1 : 2);
				for(int i = 0; i < cnt[1]+cnt[2]-1; i++) cur.push_back(3-cur.back());
				bool fail = false;
				if(start == 0 || start == 3) {
					if(cur[0] == (start^1)) cur.insert(begin(cur), start);
					else if(cur.back() == (start^1)) {
						cur.push_back(start);
						reverse(begin(cur), end(cur));
					}
					else fail = true;
				}
				if(!fail) {
					bool found1 = false, found2 = false;
					for(int i = 0; i < (int)cur.size(); i++) if(cur[i] == 1) {
						vector<int> nxt = cur;
						nxt.resize(i+1);
						for(int j = 0; j < cnt[0]; j++) {
							nxt.push_back(0);
							nxt.push_back(1);
						}
						for(int j = i+1; j < (int)cur.size(); j++) nxt.push_back(cur[j]);
						cur = nxt;
						found1 = true;
						break;
					}
					for(int i = 0; i < (int)cur.size(); i++) if(cur[i] == 2) {
						vector<int> nxt = cur;
						nxt.resize(i+1);
						for(int j = 0; j < cnt[3]; j++) {
							nxt.push_back(3);
							nxt.push_back(2);
						}
						for(int j = i+1; j < (int)cur.size(); j++) nxt.push_back(cur[j]);
						cur = nxt;
						found2 = true;
						break;
					}
					if(!found1 && !found2) { // empty
						for(int i = 0; i < cnt[0]; i++) {
							cur.push_back(0);
							cur.push_back(1);
						}
						for(int i = 0; i < cnt[3]; i++) {
							cur.push_back(2);
							cur.push_back(3);
						}
					}
					else if(!found1) { // end 2
						for(int i = 0; i < cnt[0]; i++) {
							cur.push_back(0);
							cur.push_back(1);
						}
					}
					else if(!found2) { // end 1
						for(int i = 0; i < cnt[3]; i++) {
							cur.push_back(2);
							cur.push_back(3);
						}
					}
					if(!fail) ans = cur;
				}
			}
			cnt[1] += cnt[0];
			cnt[2] += cnt[3];
		}
		if(start == 0 || start == 3) cnt[start]++;
	}
	if(ans.empty()) cout << "NO\n";
	else {
		cout << "YES\n";
		for(int i = 0; i < (int)ans.size(); i++)
			cout << ans[i] << ((i+1 == (int)ans.size()) ? "\n" : " ");
	}
	return 0;
}

// look at my code
// my code is amazing