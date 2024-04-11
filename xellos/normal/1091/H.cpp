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
	int N, F, MX = 200000;
	cin >> N >> F;
	vector<int> p1, p2;
	vector<bool> is_prime(MX+1, true);
	for(int i = 2; i <= MX; i++) if(is_prime[i]) {
		p1.push_back(i);
		for(int j = 2; j <= MX/i; j++) is_prime[j*i] = false;
	}
	for(int i = 0; i < (int)p1.size(); i++) for(int j = 0; j <= i; j++) {
		if(p1[i]*p1[j] > MX) break;
		p2.push_back(p1[i]*p1[j]);
	}
	sort(begin(p2), end(p2));
	int id_F1 = -1, id_F2 = -1;
	for(int i = 0; i < (int)p1.size(); i++) if(p1[i] == F) id_F1 = i;
	for(int i = 0; i < (int)p2.size(); i++) if(p2[i] == F) id_F2 = i;
	vector<unsigned char> is_dif(MX+1, 0);
	for(int i = 0; i < (int)p1.size(); i++) if(p1[i] != F) is_dif[p1[i]] = 1;
	for(int i = 0; i < (int)p2.size(); i++) if(p2[i] != F) is_dif[p2[i]] = 1;

	vector<unsigned char> SG(MX+1, 0);
	unsigned char max_sg = 0;
	int dif = 0;
	vector< vector<int> > pos(1, {0});
	for(int i = 1; i < 30000; i++) {
		vector<int> ex(max_sg+1, 0);
		for(int j = 0; j < (int)p1.size(); j++) {
			if(p1[j] > i) break;
			if(p1[j] == F) continue;
			ex[SG[i-p1[j]]]++;
		}
		for(int j = 0; j < (int)p2.size(); j++) {
			if(p2[j] > i) break;
			if(p2[j] == F) continue;
			ex[SG[i-p2[j]]]++;
		}
		while(SG[i] <= max_sg && ex[SG[i]] > 0) SG[i]++;
		max_sg = max(max_sg, SG[i]);
		pos.resize(max_sg+1);
		pos[SG[i]].push_back(i);
	}
	int id_m1 = 0, id_m2 = 0;
	for(int i = 30000; i <= MX; i++) {
		while(id_m1 < (int)p1.size() && p1[id_m1] <= i) id_m1++;
		while(id_m2 < (int)p2.size() && p2[id_m2] <= i) id_m2++;
		vector<int> ex(max_sg+1, 0);
		for(int j = 0; j < 800; j++) {
			if(p1[j] > i) break;
			if(p1[j] == F) continue;
			ex[SG[i-p1[j]]]++;
		}
		if(id_m1 > 2000) for(int j = 0; j < 800; j++) {
			if(p1[id_m1-2000+j] > i) break;
			if(p1[id_m1-2000+j] == F) continue;
			ex[SG[i-p1[id_m1-2000+j]]]++;
		}
		for(int j = 0; j < 800; j++) {
			if(p2[j] > i) break;
			if(p2[j] == F) continue;
			ex[SG[i-p2[j]]]++;
		}
		if(id_m2 > 2000) for(int j = 0; j < 800; j++) {
			if(p2[id_m2-2000+j] > i) break;
			if(p2[id_m2-2000+j] == F) continue;
			ex[SG[i-p2[id_m2-2000+j]]]++;
		}
		for(int j = 0; j < 2000; j++) if(is_dif[i-j]) ex[SG[j]]++;
		for(int j = 0; j <= max_sg; j++) if(ex[j] == 0) {
			int L = pos[j].size();
			for(int k = 0; k < min(400, L); k++) if(is_dif[i-pos[j][k]]) {
				ex[j] = 1;
				break;
			}
			if(L > 400) for(int k = 0; k < 300; k++) if(is_dif[i-pos[j][L-1-k]]) {
				ex[j] = 1;
				break;
			}
			if(L > 800) for(int k = 0; k < 300; k++) if(is_dif[i-pos[j][L/2-k]]) {
				ex[j] = 1;
				break;
			}
		}
		while(SG[i] <= max_sg && ex[SG[i]] > 0) SG[i]++;
		max_sg = max(max_sg, SG[i]);
		pos.resize(max_sg+1);
		pos[SG[i]].push_back(i);
	}

	int X = 0;
	for(int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		X ^= SG[b-a-1] ^ SG[c-b-1];
	}
	cout << ((X == 0) ? "Bob\nAlice\n" : "Alice\nBob\n");
	return 0;
}

// look at my code
// my code is amazing