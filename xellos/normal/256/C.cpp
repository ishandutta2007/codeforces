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
	vector<int> SG(1000000,0);
	for(int i =2; i <= 100; i++) {
		set<int> s;
		for(int j =1; j < i; j++) if(j*j*j*j >= i && j*j <= i) s.insert(SG[j]);
		while(s.find(SG[i]) != s.end()) SG[i]++;}
	int sq =10;
	for(int i =101; i < 1000000; i++) {
		if((sq+1)*(sq+1) <= i) sq++;
		if(i > sq*sq+1) {SG[i] =SG[i-1]; continue;}
		set<int> s;
		for(int j =1; j <= sq; j++) if(j*j*j*j >= i) s.insert(SG[j]);
		while(s.find(SG[i]) != s.end()) SG[i]++;}

	int mx_SG =0;
	for(int i =1; i < 1000000; i++) mx_SG =max(mx_SG,SG[i]);
	vector< set<int> > V(mx_SG+tisic);
	for(int i =1; i < 1000000; i++) V[SG[i]].insert(i);

	int N;
	scanf(" %d",&N);
	int x =0;
	for(int i =0; i < N; i++) {
		long long a;
		scanf(" %I64d",&a);
		long long sqa =sqrt(a);
		while(sqa*sqa > a) sqa--;
		while((sqa+1)*(sqa+1) <= a) sqa++;
		sqa =min(sqa,a-1);
		long long qa =sqrt(sqa);
		while(qa*qa*qa*qa < a) qa++;
		while(qa > 0 && (qa-1)*(qa-1)*(qa-1)*(qa-1) >= a) qa--;

		int SG_akt =0;
		while(true) {
			auto it =V[SG_akt].lower_bound(qa);
			if(it != V[SG_akt].end() && *it <= sqa) SG_akt++;
			else break;}
 		x ^=SG_akt;}

	if(x == 0) printf("Rublo\n");
	else printf("Furlo\n");
	return 0;}

// look at my code
// my code is amazing