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
#define OVER9000 12345678901234567LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,M,a,b;
	cin >> N >> M;
	vector< vector<int> > adjL(N);
	for(int i =0; i < M; i++) {
		cin >> a >> b;
		adjL[--a].push_back(--b);
		adjL[b].push_back(a);}
	
	for(int i =0; i < N; i++) if(adjL[i].size() > 2) {
		cout << " -1\n";
		return 0;}
	
	vector<int> free(N,true);
	vector< vector<int> > T;
	for(int i =0; i < N; i++) if(free[i]) if(adjL[i].size() == 2) {
		if(!free[adjL[i][0]] || !free[adjL[i][1]]) {
			cout << "-1\n";
			return 0;}
		T.resize(T.size()+1);
		T[T.size()-1].push_back(i);
		T[T.size()-1].push_back(adjL[i][0]);
		T[T.size()-1].push_back(adjL[i][1]);
		free[i] =free[adjL[i][0]] =free[adjL[i][1]] =false;}
	for(int i =0; i < N; i++) if(free[i]) if(adjL[i].size() == 1) {
		if(!free[adjL[i][0]]) {
			cout << "-1\n";
			return 0;}
		T.resize(T.size()+1);
		T[T.size()-1].push_back(i);
		T[T.size()-1].push_back(adjL[i][0]);
		free[i] =free[adjL[i][0]] =false;}
	for(int i =0; i < N; i++) if(free[i]) {
		for(int j =0; j < T.size(); j++) if(T[j].size() < 3) {
			free[i] =false;
			T[j].push_back(i);
			break;}
		if(free[i]) {
			T.resize(T.size()+1);
			T[T.size()-1].push_back(i);
			free[i] =false;}}
	if(T.size()*3 != N) {
		cout << "-1\n";
		return 0;}

	for(int i =0; i < T.size(); i++) {
		if(T[i].size() != 3) {
			cout << "-1\n";
			return 0;}
		for(int j =0; j < 3; j++) for(int k =0; k < adjL[T[i][j]].size(); k++) {
			bool b =false;
			for(int l =0; l < 3; l++) if(adjL[T[i][j]][k] == T[i][l]) {
				b =true;
				continue;}
			if(!b) {
				cout << "-1\n";
				return 0;}}}
	for(int i =0; i < T.size(); i++)
		cout << T[i][0]+1 << " " << T[i][1]+1 << " " << T[i][2]+1 << endl;
	return 0;}
        
// look at my code
// my code is amazing