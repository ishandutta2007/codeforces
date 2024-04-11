// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	vector<string> ans =V;
	bool has_ans =false;

	for(int k =0; k < 2; k++) {
		// farby podla riadkov
		vector<int> pe(4,0), po(4,0);
		for(int i =0; i < N; i++) for(int j =0; j < M; j++)
			if(V[i][j] != '0') {
				if(i%2 == 0) pe[V[i][j]-'1']++;
				else po[V[i][j]-'1']++;}
		int Pe =0, Po =0;
		vector<int> Ce,Co;
		for(int i =0; i < 4; i++) {
			if(pe[i] > 0) Pe++, Ce.push_back(i);
			if(po[i] > 0) Po++, Co.push_back(i);}
		for(int i =0; i < 4; i++) if(pe[i] == 0 && po[i] == 0) {
			if(Pe < 2) Pe++, pe[i] =1, Ce.push_back(i);
			else if(Po < 2) Po++, po[i] =1, Co.push_back(i);}
		vector<string> ans_akt =V;
		if(Pe == 2 && Po == 2) for(int i =0; i < N; i++) {
			bool done =false;
			for(int j =0; j < M; j++) if(V[i][j] != '0') {
				int c =(i%2 == 0)?Ce[0]:Co[0], c2 =(i%2 == 0)?Ce[1]:Co[1];
				if(c != V[i][j]-'1') swap(c,c2);
				for(int k =0; k < M; k++) ans_akt[i][k] ='1'+(((k-j)%2 == 0)?c:c2);
				done =true;
				break;}
			if(!done) {
				if(i%2 == 0) for(int j =0; j < M; j++) ans_akt[i][j] ='1'+((j%2 == 0)?Ce[0]:Ce[1]);
				else for(int j =0; j < M; j++) ans_akt[i][j] ='1'+((j%2 == 0)?Co[0]:Co[1]);}
			}
		// test
		bool ok =true;
		for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
			if(ans_akt[i][j] == '0') ok =false;
			if(V[i][j] != '0' && ans_akt[i][j] != V[i][j]) ok =false;}
		for(int i =0; i < N; i++) for(int j =1; j < M; j++) if(ans_akt[i][j] == ans_akt[i][j-1]) ok =false;
		for(int i =1; i < N; i++) for(int j =0; j < M; j++) if(ans_akt[i][j] == ans_akt[i-1][j]) ok =false;
		for(int i =1; i < N; i++) for(int j =1; j < M; j++) if(ans_akt[i][j] == ans_akt[i-1][j-1]) ok =false;
		for(int i =0; i < N-1; i++) for(int j =1; j < M; j++) if(ans_akt[i][j] == ans_akt[i+1][j-1]) ok =false;
		if(ok) ans =ans_akt, has_ans =true;
		// flip
		vector<string> V_nw(M);
		for(int i =0; i < M; i++) for(int j =0; j < N; j++) V_nw[i] +=V[j][i];
		V =V_nw;
		vector<string> ans_nw(M);
		for(int i =0; i < M; i++) for(int j =0; j < N; j++) ans_nw[i] +=ans[j][i];
		ans =ans_nw;
		swap(N,M);}

	if(!has_ans) {cout << "0\n"; return 0;}
	for(int i =0; i < N; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing