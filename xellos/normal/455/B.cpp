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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

struct node {
	int son[26];
	bool wins[2];
	};

struct trie {
	vector<node> T;
	node n0;

	trie() {
		for(int i =0; i < 26; i++) n0.son[i] =-1;
		n0.wins[0] =n0.wins[1] =false;
		T.resize(1,n0);
		T.dibs(100000);}

	void put(string s) {
		int L =s.length(), akt =0;
		for(int i =0; i < L; i++) {
			if(T[akt].son[s[i]-'a'] == -1) {
				T[akt].son[s[i]-'a'] =T.size();
				T.push_back(n0);}
			akt =T[akt].son[s[i]-'a'];}
		}

	void calc(int akt) {
		bool S =true;
		for(int i =0; i < 26; i++) if(T[akt].son[i] != -1) {
			calc(T[akt].son[i]);
			S =false;
			if(!T[T[akt].son[i]].wins[1]) T[akt].wins[1] =true;
			if(!T[T[akt].son[i]].wins[0]) T[akt].wins[0] =true;}
		if(S) T[akt].wins[1] =true; // vie prehrat
		}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	trie tr;
	for(int i =0; i < N; i++) {
		string s;
		cin >> s;
		tr.put(s);}
	tr.calc(0);

	if(!tr.T[0].wins[0]) { // druhy vie vyhrat
		cout << "Second\n";
		return 0;}
	// prvy vie vyhrat
	// predposlednu hru prehra aby vyhral
	// zac. v K-2. vyhra -> K-1. prehra -> vyhra
//	cout << tr.T[0].wins[0] << "  " << tr.T[0].wins[1] << "\n";
	if(!tr.T[0].wins[1]) {
		if(K%2 == 1) cout << "First\n";
		else cout << "Second\n";
		return 0;}

	// prvy vie vyhrat aj prehrat
	cout << "First\n";
	return 0;}

// look at my code
// my code is amazing