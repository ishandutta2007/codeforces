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
#define soclose 1e-8
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

vector<int> prP;
vector<int> all_num,good_num;

void bt(int p_akt, int akt, int mx, int P, vector<int> &pdec) {
	int poc =0, aktpr =1;
	for(auto it =pdec.rbegin(); it != pdec.rend(); it++) {
		if(aktpr*(*it) > p_akt) {aktpr =1; poc++;}
		aktpr *=*it;}
	if(prP[p_akt]+poc <= P) good_num.push_back(akt);
	else all_num.push_back(akt);
	for(int i =p_akt; i < (int)prP.size(); i++) {
		pdec.push_back(prP[i]);
		if(1LL*prP[i]*akt <= mx) bt(i,akt*prP[i],mx,P,pdec);
		pdec.pop_back();}
	}

int K =13000000;

bool bt2(int akt, int d_akt, vector<int> &divs, vector< vector<short> > &minM, int P) {
	if(P < 0) return false;
	if(akt <= K) return (minM[akt][divs[d_akt]] <= P);
	for(int i =d_akt; i < (int)divs.size(); i++) if(akt%divs[i] == 0)
		if(bt2(akt/divs[i],i,divs,minM,P-1)) return true;
	return false;}

int main() {
	int L,R,P;
	scanf(" %d %d %d",&L,&R,&P);
	for(int i =2; i <= P; i++) {
		bool isP =true;
		for(int j =2; j < i; j++) if(i%j == 0) isP =false;
		if(isP) prP.push_back(i);}
	all_num.dibs(3000000);
	vector<int> pdec;
	bt(0,1,R,P,pdec);

	vector< vector<short> > minM(K+tisic);
	ALL_THE(all_num,it) if(*it <= K) minM[*it].resize(P+1,1000);
	ALL_THE(good_num,it) if(*it <= K) minM[*it].resize(P+1,1000);
	for(int i =1; i <= K; i++) if(!minM[i].empty()) {
		if(i == 1) minM[i][1] =0;
		for(int j =2; j <= P; j++) {
			minM[i][j] =minM[i][j-1];
			if(i%j == 0) minM[i][j] =min(minM[i][j],(short)(minM[i/j][j]+1));}
		}

	ALL_THE(good_num,it) if(*it <= K) {
		short minP =1000;
		for(int i =P; i >= 0; i--) {
			minP =min(minP,(short)(i+minM[*it][i]));
			minM[*it][i] =minP;}
		}
	ALL_THE(all_num,it) if(*it <= K) {
		short minP =1000;
		for(int i =P; i >= 0; i--) {
			minP =min(minP,(short)(i+minM[*it][i]));
			minM[*it][i] =minP;}
		}

	int ans =0;
	ALL_THE(good_num,it) if(*it >= L && *it <= R) ans++;
	ALL_THE(all_num,it) if(*it >= L && *it <= R) {
		if(*it == 1) {ans++; continue;}
		vector<int> divs;
		for(int i =2; i <= P; i++) if((*it)%i == 0) divs.push_back(i);
		if(bt2(*it,0,divs,minM,P)) ans++;}

	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing