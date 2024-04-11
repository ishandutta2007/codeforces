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
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		if(pos < 0) return;
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<bool> used(N,false);
	vector<int> pos(N,-OVER9000);
	int p =0, sh =0;
	fin F(N);
	vector<int> init(N,-1);
	for(int i =0; i < N; i++) F.put(i,1);
	fin F2(N);

	for(int i =0; i < M; i++) {
		int x,y;
		cin >> x >> y;
		x--, y--;
		if(y < p) {
			if(pos[x]+sh-F2.get(pos[x]+N) != y) {cout << "-1\n"; return 0;}
			sh++;
			F2.put(pos[x]+N,1);
			pos[x] =-sh;			
			continue;}
		if(pos[x]+sh >= 0) {cout << "-1\n"; return 0;}
		used[x] =true;
		// ...+p == y
		int A =-1, B =N;
		while(B-A > 1) {
			if(F.get((B+A)/2)+p >= y+1) B =(A+B)/2;
			else A =(A+B)/2;}
		init[B] =x;
		F.put(B,-1);
		sh++;
		pos[x] =-sh;
		p++;}
	
	int a =0;
	for(int i =0; i < N; i++) if(init[i] < 0) {
		while(used[a]) a++;
		used[a] =true;
		init[i] =a;}
	for(int i =0; i < N; i++) cout << init[i]+1 << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing