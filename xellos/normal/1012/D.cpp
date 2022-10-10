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
#define OVER9000 1234567890123456789LL
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

struct group {
	char c;
	int l, r;

	group operator+(int x) const {
		return {c, l+x, r+x};
	}

	group operator-(int x) const {
		return {c, l-x, r-x};
	}
};

void apply(vector<group> & gA, vector<group> & gB, int prefA, int prefB, vector<group> & gA_nw, vector<group> & gB_nw) {
	gA_nw.reserve(prefB+(int)gA.size()-prefA);
	gB_nw.reserve(prefA+(int)gB.size()-prefB);
	for(int i = 0; i < prefA; i++) gB_nw.push_back(gA[i]);
	for(int i = 0; i < prefB; i++) gA_nw.push_back(gB[i]);
	if(gB_nw.empty() || gB_nw.back().c != gB[prefB].c) {
		int dl = -gB[prefB].l + (gB_nw.empty() ? 0 : gB_nw.back().r);
		for(int i = prefB; i < (int)gB.size(); i++) gB_nw.push_back(gB[i]+dl);
	}
	else {
		gB_nw.back().r += gB[prefB].r-gB[prefB].l;
		if(prefB+1 < (int)gB.size()) {
			int dl = -gB[prefB+1].l + gB_nw.back().r;
			for(int i = prefB+1; i < (int)gB.size(); i++) gB_nw.push_back(gB[i]+dl);
		}
	}
	gB_nw[0].l = 0;
	if(gA_nw.empty() || gA_nw.back().c != gA[prefA].c) {
		int dl = -gA[prefA].l + (gA_nw.empty() ? 0 : gA_nw.back().r);
		for(int i = prefA; i < (int)gA.size(); i++) gA_nw.push_back(gA[i]+dl);
	}
	else {
		gA_nw.back().r += gA[prefA].r-gA[prefA].l;
		if(prefA+1 < (int)gA.size()) {
			int dl = -gA[prefA+1].l + gA_nw.back().r;
			for(int i = prefA+1; i < (int)gA.size(); i++) gA_nw.push_back(gA[i]+dl);
		}
	}
	gA_nw[0].l = 0;
}

void finish_ops(vector<group> gA, vector<group> gB, vector< pair<int, int> > & ans, int sw) {
	for(int i = 0; i < (int)gA.size(); i++) gA[i].r -= gA[i].l;
	for(int i = 0; i < (int)gB.size(); i++) gB[i].r -= gB[i].l;
	for(int i = 1; i < (int)gA.size(); i++) {
		if(sw == 0) ans.push_back({gA[i-1].r, gB[i-1].r});
		else ans.push_back({gB[i-1].r, gA[i-1].r});
		gA[i].r += gB[i-1].r;
		gB[i].r += gA[i-1].r;
	}
}

int decode(char c, int l) {
	if(c >= '0' && c <= '9') return c-'0';
	if(c == 'h') return l/2;
	if(c == 'H') return l/2+1;
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S[2];
	cin >> S[0] >> S[1];
	bool ans_found = false;
	vector< pair<int, int> > ans;
	string ops[] = {"01", "10", "hh", "hH", "Hh", "HH", "h0", "H0", "0h", "0H"};
	for(int k = 0; k < 2; k++) {
		string A = S[k], B = S[1-k];
		bool sw = k;
		A += 'a';
		B += 'b';
		vector<group> gA, gB;
		for(int i = 0; i < (int)A.length(); i++) if(i == 0 || A[i-1] != A[i]) {
			int l = i, r = i;
			while(r < (int)A.length() && A[r] == A[i]) r++;
			gA.push_back({A[i], l, r});
		}
		for(int i = 0; i < (int)B.length(); i++) if(i == 0 || B[i-1] != B[i]) {
			int l = i, r = i;
			while(r < (int)B.length() && B[r] == B[i]) r++;
			gB.push_back({B[i], l, r});
		}
		// 0 extra ops
		if(gA.size() == gB.size() && (!ans_found || gA.size()-1 < ans.size())) {
			ans = vector< pair<int, int> >();
			finish_ops(gA, gB, ans, sw);
			ans_found = true;
		}
		int op_id[2];
		for(op_id[0] = 0; op_id[0] < 6; op_id[0]++) {
			int prefA0 = decode(ops[op_id[0]][0], gA.size()), prefB0 = decode(ops[op_id[0]][1], gB.size());
			if(prefA0 >= (int)gA.size() || prefB0 >= (int)gB.size()) continue;
			vector<group> gA_nw0, gB_nw0;
			apply(gA, gB, prefA0, prefB0, gA_nw0, gB_nw0);
			// 1 extra op
			if(gA_nw0.size() == gB_nw0.size() && (!ans_found || gA_nw0.size() < ans.size())) {
				ans = vector< pair<int, int> >(1);
				if(sw == 0) ans[0] = {prefA0 ? gA[prefA0-1].r : 0, prefB0 ? gB[prefB0-1].r : 0};
				else ans[0] = {prefB0 ? gB[prefB0-1].r : 0, prefA0 ? gA[prefA0-1].r : 0};
				finish_ops(gA_nw0, gB_nw0, ans, sw);
				ans_found = true;
			}
			// 2 extra ops
			for(op_id[1] = 0; op_id[1] < 6; op_id[1]++) {
				int prefA1 = decode(ops[op_id[1]][0], gA_nw0.size()), prefB1 = decode(ops[op_id[1]][1], gB_nw0.size());
				if(prefA1 >= (int)gA_nw0.size() || prefB1 >= (int)gB_nw0.size()) continue;
				if((gA_nw0.size()+gB_nw0.size())%2 != 0 && op_id[1] >= 2) continue;
				vector<group> gA_nw1, gB_nw1;
				apply(gA_nw0, gB_nw0, prefA1, prefB1, gA_nw1, gB_nw1);
				if(gA_nw1.size() == gB_nw1.size() && (!ans_found || gA_nw1.size()+1 < ans.size())) {
					ans = vector< pair<int, int> >(2);
					if(sw == 0) {
						ans[0] = {prefA0 ? gA[prefA0-1].r : 0, prefB0 ? gB[prefB0-1].r : 0};
						ans[1] = {prefA1 ? gA_nw0[prefA1-1].r : 0, prefB1 ? gB_nw0[prefB1-1].r : 0};
					}
					else {
						ans[0] = {prefB0 ? gB[prefB0-1].r : 0, prefA0 ? gA[prefA0-1].r : 0};
						ans[1] = {prefB1 ? gB_nw0[prefB1-1].r : 0, prefA1 ? gA_nw0[prefA1-1].r : 0};
					}
					finish_ops(gA_nw1, gB_nw1, ans, sw);
					ans_found = true;
				}
			}
		}
	}
	cout << ans.size() << "\n";
	ALL_THE(ans, it) cout << it->ff << " " << it->ss << "\n";
	return 0;
}

// look at my code
// my code is amazing