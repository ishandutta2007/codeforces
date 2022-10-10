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
	string S;
	cin >> S;
	int N = S.length();
	vector< vector<int> > G(2*N);
	cat mod = 998244353;
	vector<cat> cnt(N, 0), comp(2*N);
	queue<int> q;
	for(int d = 1; d < N; d++) {
		for(int i = 0; i < 2*N; i++) G[i].clear();
		for(int i = 0; i < N; i++) if(i != N-1-i) G[i].push_back(N-1-i);
		for(int i = d; i < N; i++) if(i != N-1-(i-d)) G[N+i].push_back(N+N-1-(i-d));
		for(int i = 0; i < N; i++) if(S[i] != '?') {
			if(S[i] == '0') {
				G[i].push_back(N+i);
				G[N+i].push_back(i);
			}
			else {
				G[i].push_back(-N-i-1);
				G[N+i].push_back(-i-1);
			}
		}
		for(int i = 1; i < d; i++) {
			G[N].push_back(N+i);
			G[N+i].push_back(N);
		}
		G[0].push_back(N+d);
		G[N+d].push_back(0);
		for(int i = 0; i < 2*N; i++) comp[i] = -1;
		int C = 0;
		for(int i = 0; i < 2*N; i++) if(comp[i] == -1) {
			q.push(i);
			comp[i] = C;
			while(!q.empty()) {
				ALL_THE(G[q.front()], it) {
					if(*it < 0) continue;
					if(comp[*it] != -1) continue;
					comp[*it] = C;
					q.push(*it);
				}
				q.pop();
			}
			C++;
		}
		vector< vector<int> > Gc(C);
		for(int i = 0; i < 2*N; i++) ALL_THE(G[i], it) if(*it < 0) {
			int c1 = comp[i], c2 = comp[-(*it)-1];
			Gc[c1].push_back(c2);
			Gc[c2].push_back(c1);
		}
		vector<int> part(C, -1);
		int CP = 0; // Club Penguin
		bool ok = true;
		for(int i = 0; i < C; i++) if(part[i] == -1) {
			part[i] = 0;
			q.push(i);
			while(!q.empty()) {
				ALL_THE(Gc[q.front()], it) {
					if(part[*it] == -1) {
						part[*it] = 1-part[q.front()];
						q.push(*it);
						continue;
					}
					if(part[*it] == part[q.front()]) {
						ok = false;
						break;
					}
				}
				q.pop();
			}
			if(!ok) {
				while(!q.empty()) q.pop();
				break;
			}
			CP++;
		}
		if(!ok) continue;
		cnt[d] = 1;
		for(int i = 0; i < CP-1; i++) cnt[d] = cnt[d] * 2 % mod;
	}
	cat ans = 0;
	for(int i = 0; i < N; i++) ans += cnt[i];
	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing