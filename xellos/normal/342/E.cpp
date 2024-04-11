// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int N,M,a,b,P;
vector< vector<int> > son;
vector<int> S; // subtree size
vector<int> par;
vector<int> inP; // v ktorej je ceste
vector<int> topP; // vrchol cesty
vector<int> depP; // hlbka v ceste
vector<int> lenP; // dlzka cesty

struct fin {
	vector<int> T;
	
	fin() {}
	fin(int N) {T.resize(N+1,OVER9000);}
	
	int lastone(int x) {return x&(x^(x-1));}
	
	void put(int pos, int val) {
		for(int i =pos+1; i < (int)T.size(); i +=lastone(i)) T[i] =min(T[i],val);}
	
	int get(int pos) {
		int ret =OVER9000;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =min(T[i],ret);
		return ret;}
	};

void init() {
	queue<int> q;
	stack<int> s;
	q.push(0);
	par[0] =0;
	while(!q.empty()) {
		a =q.front();
		s.push(a);
		for(uint i =0; i < son[a].size(); i++) if(par[son[a][i]] == -1) {
			q.push(son[a][i]);
			par[son[a][i]] =a;}
		q.pop();}

	for(int i =0; i < N; i++) for(uint j =0; j < son[i].size(); j++) if(par[i] == son[i][j]) {
		if(j != son[i].size()-1) swap(son[i][j],son[i][son[i].size()-1]);
		son[i].pop_back();
		break;}

	while(!s.empty()) {
		a =s.top(), b =0;
		for(uint i =0; i < son[a].size(); i++) {
			S[a] +=S[son[a][i]];
			if(S[son[a][i]] > b) {
				S[son[a][i]] =b;
				inP[a] =inP[son[a][i]];}}
		if(inP[a] == -1) {
			inP[a] =P; 
			topP.push_back(-1); 
			P++;}
		for(uint i =0; i < son[a].size(); i++) 
			if(inP[a] != inP[son[a][i]]) topP[inP[son[a][i]]] =son[a][i];
		s.pop();}
	topP[inP[0]] =0;

	depP.resize(N,1);
	lenP.resize(P,1);
	for(int i =0; i < P; i++) depP[topP[i]] =0;
	q.push(0);
	while(!q.empty()) {
		a =q.front();
		lenP[inP[a]] =max(lenP[inP[a]],depP[a]+1);
		for(uint i =0; i < son[a].size(); i++) {
			q.push(son[a][i]);
			if(depP[son[a][i]] != 0) depP[son[a][i]] =depP[a]+1;}
		q.pop();}
	}

vector<fin> F;
vector<fin> Fi;
	
void putNode(int x) {
	int D =0, akt =x;
	while(true) {
		F[inP[akt]].put(depP[akt],D-depP[akt]);
		Fi[inP[akt]].put(lenP[inP[akt]]-1-depP[akt],D+depP[akt]);
		D +=depP[akt]+1;
		if(topP[inP[akt]] == 0) break;
		akt =par[topP[inP[akt]]];}
	}

int getDist(int x) {
	int D =0, akt =x, ret =OVER9000;
	while(true) {
		// nad nim
		ret =min(ret,F[inP[akt]].get(depP[akt])+depP[akt]+D);
		// pod nim
		ret =min(ret,Fi[inP[akt]].get(lenP[inP[akt]]-1-depP[akt])-depP[akt]+D);
		if(topP[inP[akt]] == 0) break;
		D +=depP[akt]+1;
		akt =par[topP[inP[akt]]];}
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin >> N >> M;
	son.resize(N);
	for(int i =0; i < N-1; i++) {
		cin >> a >> b;
		son[--a].push_back(--b);
		son[b].push_back(a);}
	par.resize(N,-1);
	S.resize(N,1);
	inP.resize(N,-1);
	P =0;
	init();
	
	F.resize(P);
	Fi.resize(P);
	for(int i =0; i < P; i++) {
		F[i].T.resize(lenP[i]+1,OVER9000);
		Fi[i].T.resize(lenP[i]+1,OVER9000);}
	putNode(0);
	for(int i =0; i < M; i++) {
		int t,v;
		cin >> t >> v;
		if(t == 1) putNode(v-1);
		else cout << getDist(v-1) << "\n";}
    return 0;}
        
// look at my code
// my code is amazing