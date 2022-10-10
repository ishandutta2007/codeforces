// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,Q;
	scanf(" %d %d",&N,&Q);
	vector< vector<int> > comp(N);
	map< pair<int,int>, int> inC;
	for(int i =0; i < N; i++) {
		comp[i].resize(1,i);
		inC[make_pair(i,i+1)] =i;}

	for(int q =0; q < Q; q++) {
		int type,x,y;
		scanf(" %d %d %d",&type,&x,&y);
		x--, y--;
		if(type == 3) {
			auto it =inC.upper_bound(make_pair(x,N+1)), jt =inC.upper_bound(make_pair(y,N+1));
			it--, jt--;
			if(it->ss == jt->ss) printf("YES\n");
			else printf("NO\n");
			continue;}
		if(type == 1) {
			auto it =inC.upper_bound(make_pair(x,N+1)), jt =inC.upper_bound(make_pair(y,N+1));
			it--, jt--;
			int c1 =it->ss, c2 =jt->ss;
			if(c1 == c2) continue;
			if(comp[c1].size() < comp[c2].size()) {
				swap(c1,c2);
				swap(it,jt);}
			ALL_THE(comp[c2],kt) {
				comp[c1].push_back(*kt);
				it =inC.upper_bound(make_pair(*kt,N+1));
				it--;
				if(it->ss != c2) continue;
				pair<int,int> p =it->ff;
				jt =it;
				if(jt != inC.begin()) {
					jt--;
					if(jt->ss == c1) {p.ff =jt->ff.ff; inC.erase(jt);}}
				jt =it;
				jt++;
				if(jt != inC.end() && jt->ss == c1) {
					p.ss =jt->ff.ss;
					inC.erase(jt);}
				inC.erase(it);
				inC[p] =c1;}
			continue;}
		vector<int> merge;
		auto it =inC.upper_bound(make_pair(x,N+1));
		it--;
		while(it != inC.end()) {
			merge.push_back(it->ff.ff);
			if(it->ff.ss > y) break;
			it++;}
		int m =merge.size();
		for(int i =1; i < m; i++) {
			it =inC.upper_bound(make_pair(merge[i-1],N+1));
			auto jt =inC.upper_bound(make_pair(merge[i],N+1));
			it--; jt--;
			int c1 =it->ss, c2 =jt->ss;
			if(c1 == c2) continue;
			if(comp[c1].size() < comp[c2].size()) {
				swap(c1,c2);
				swap(it,jt);}
			ALL_THE(comp[c2],kt) {
				comp[c1].push_back(*kt);
				it =inC.upper_bound(make_pair(*kt,N+1));
				it--;
				if(it->ss != c2) continue;
				pair<int,int> p =it->ff;
				jt =it;
				if(jt != inC.begin()) {
					jt--;
					if(jt->ss == c1) {p.ff =jt->ff.ff; inC.erase(jt);}}
				jt =it;
				jt++;
				if(jt != inC.end() && jt->ss == c1) {
					p.ss =jt->ff.ss;
					inC.erase(jt);}
				inC.erase(it);
				inC[p] =c1;}
			}
		}
	return 0;}

// look at my code
// my code is amazing