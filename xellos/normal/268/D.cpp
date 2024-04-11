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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

long long poc[4000000];
long long poc_new[4000000];

int hV(vector<int> v) {
	int ret =0;
	for(uint i =0; i < v.size(); i++) ret =50*ret+v[i];
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	long long mod =1000000009;
	int N,H;
	cin >> N >> H;

	vector< pair<int,int> > pos[4];
	vector<int> pos_all;
	for(int i =0; i <= H; i++) for(int j =i; j <= H; j++) for(int k =j; k <= H; k++)
		for(int l =k; l <= H; l++) if(i == 0 || j == 0 || k == 0 || l == 0 || i == H || j == H || k == H || l == H) {
			vector<int> v(1,i); v.push_back(j);
			v.push_back(k); v.push_back(l);
			pos_all.push_back(hV(v));
			vector<int> w =v;
			for(int m =0; m < 4; m++) w[m] =min(v[m]+1,H);
			if(i < H) w[0] =0;
			sort(begin(w),end(w));
			pos[0].push_back(make_pair(hV(v),hV(w)));
			for(int m =0; m < 4; m++) w[m] =min(v[m]+1,H);
			if(j < H) w[1] =0;
			sort(begin(w),end(w));
			pos[1].push_back(make_pair(hV(v),hV(w)));
			for(int m =0; m < 4; m++) w[m] =min(v[m]+1,H);
			if(k < H) w[2] =0;
			sort(begin(w),end(w));
			pos[2].push_back(make_pair(hV(v),hV(w)));
			for(int m =0; m < 4; m++) w[m] =min(v[m]+1,H);
			if(l < H) w[3] =0;
			sort(begin(w),end(w));
			pos[3].push_back(make_pair(hV(v),hV(w)));}

	poc[0] =1;
	for(int i =0; i < N; i++) {
		for(int k =0; k < 4; k++) ALL_THE(pos[k],it) {
			int v =it->ff, w =it->ss;
			poc_new[w] +=poc[v];
			if(poc_new[w] >= mod) poc_new[w] -=mod;
			}
		ALL_THE(pos_all,it) {
			int v =*it;
			poc[v] =poc_new[v];
			poc_new[v] =0;
			}
		}

	long long ans =0;
	for(int i =0; i <= H; i++) for(int j =0; j <= H; j++) for(int k =0; k <= H; k++)
		for(int l =0; l <= H; l++) if(!(i == H && j == H && k == H && l == H)) {
			vector<int> v(1,i); v.push_back(j);
			v.push_back(k); v.push_back(l);
			ans +=poc[hV(v)];
			if(ans >= mod) ans -=mod;}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing