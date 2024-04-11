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
#define OVER9000 12345678901234567LL
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

struct info {
	int C[2];
	int D,id,rot;

	bool operator<(const info &A) const {
		return C[0] > A.C[0];}
	};

int main() {
	cin.sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	int D[2] ={0,0};
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
		string s;
		cin >> s;
		if(s[0] == '1' && s[1] == '1') D[0]++;
		if(s[0] != s[1]) D[1]++;}

	priority_queue<info> q;
	for(int i =0; i < M; i++) {
		info I;
		I.id =i;
		I.D =I.C[0] =I.C[1] =I.rot =0;
		q.push(I);}

	vector<string> ans(N);
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) ans[i] +="00";

	for(int i =0; i < D[0]; i++) {
		info I =q.top(); q.pop();
		ans[I.D][2*I.id] =ans[I.D][2*I.id+1] ='1';
		I.D++;
		I.C[0]++, I.C[1]++;
		if(I.D < N) q.push(I);}

	for(int i =0; i < D[1]; i++) {
		info I =q.top(); q.pop();
		ans[I.D][2*I.id+I.rot] ='1';
		I.D++;
		I.C[0]++;
		if(I.C[0] > I.C[1]) {
			swap(I.C[0],I.C[1]);
			I.rot =1-I.rot;}
		if(I.D < N) q.push(I);}

	for(int i =0; i < N; i++)
		for(int j =0; j < M; j++) cout << ans[i][2*j] << ans[i][2*j+1] << ((j == M-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing