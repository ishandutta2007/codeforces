#include <bits/stdc++.h>
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
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

struct fin {
	vector< vector<int> > T;
	fin(int N, int M) {T.resize(N+tisic,vector<int>(M+tisic,0));}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int posX, int posY, int val) {
		for(int i =posX+1; i < T.size(); i +=lastone(i))
			for(int j =posY+1; j < T[i].size(); j +=lastone(j))
				T[i][j] +=val;
		}

	int get(int posX, int posY) {
		int ret =0;
		for(int i =posX+1; i > 0; i -=lastone(i))
			for(int j =posY+1; j > 0; j -=lastone(j))
				ret +=T[i][j];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];

	int ans =0;
	fin F(N,M);
	for(int i =N-1; i >= 0; i--) for(int j =M-1; j >= 0; j--) {
		int x =((V[i][j] == 'B')?1:-1);
		x +=F.get(N-i,M-j);
		if(x != 0) {
			ans++;
			F.put(N-i,M-j,-x);}
		}
	
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing