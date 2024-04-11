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
#define dbl long double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N,Q;
	scanf(" %d %d",&N,&Q);
	char ch[100000+tisic];
	scanf(" %s",ch);
	string s =(string)ch;

	map<int, pair<int,int> > M[26];
	for(int i =0; i < N; i++) M[s[i]-'a'][i] =make_pair(i+1,0);
	for(int k =0; k < 26; k++) {
		M[k][-1] =make_pair(0,0);
		int a =0;
		ALL_THE(M[k],it) it->ss.ss =a++;}

	for(int q =0; q < Q; q++) {
		int l,r;
		scanf(" %d %d",&l,&r);
		l--; // [l,r)
		pair<map<int, pair<int,int> >::iterator,map<int, pair<int,int> >::iterator> its[26];
		int poc[26];
		int odd =0;
		for(int k =0; k < 26; k++) {
			auto it =M[k].lower_bound(r);
			its[k].ss =--it;
			poc[k] =it->ss.ss-max(0,it->ss.ff-r); // pocet pred r
			it =M[k].lower_bound(l);
			its[k].ff =--it;
			poc[k] -=it->ss.ss-max(0,it->ss.ff-l); // medzi [l,r)
			if(poc[k]%2 != 0) odd++;}
		if(odd > 1) continue;
		int sum =0;
		int sum0[26];
		for(int k =0; k < 26; k++) if(poc[k] > 0) {
			auto jt =its[k].ss;
			if(jt->ss.ff > r) M[k][r] =jt->ss;
			auto it =its[k].ff;
			it->ss.ss -=max(0,it->ss.ff-l);
			sum0[k] =it->ss.ss;
			it->ss.ff =min(it->ss.ff,l);
			while(jt != it) {
				auto kt =jt; jt--;
				M[k].erase(kt);}
			}
		for(int k =0; k < 26; k++) {
			if(poc[k] > 1) M[k][l+sum] =make_pair(l+sum+poc[k]/2,sum0[k]+poc[k]/2);
			if(poc[k] > 1) M[k][r-sum-poc[k]/2] =make_pair(r-sum,sum0[k]+poc[k]);
			if(poc[k]%2 != 0) M[k][(l+r)/2] =make_pair((l+r)/2+1,sum0[k]+poc[k]/2+1);
			sum +=poc[k]/2;}
		}

	for(int k =0; k < 26; k++)
		ALL_THE(M[k],it) 
			for(int i =it->ff; i < it->ss.ff; i++) s[i] =(char)('a'+k);
	printf("%s\n",s.c_str());
	return 0;}

// look at my code
// my code is amazing