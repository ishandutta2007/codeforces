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
#include <time.h>
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
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S[2];
	cin >> S[0] >> S[1];
	int N =S[0].length();
	int n =N, h =0;
	while(n%2 == 0) n /=2, h++;

	vector<string> split[2];
	map<string,int> M;
	for(int k =0; k < 2; k++) {
		split[k].resize(N/n);
		for(int i =0; i < N/n; i++) {
			for(int j =0; j < n; j++) split[k][i] +=S[k][i*n+j];
			M[split[k][i]] =0;}
		}
	
	int m =0;
	ALL_THE(M,it) it->ss =m++;

	vector<int> splitV[2];
	for(int k =0; k < 2; k++) {
		splitV[k].resize(N/n);
		for(int i =0; i < N/n; i++) splitV[k][i] =M[split[k][i]];
		for(int j =0; j < h; j++)
			for(int i =0; i < N/n; i +=(1<<(j+1))) {
				int comp =0;
				for(int l =0; l < (1<<j); l++) if(split[k][i+l] != split[k][i+(1<<j)+l]) {
					if(split[k][i+l] < split[k][i+(1<<j)+l]) comp =-1;
					else comp =1;
					break;}
				if(comp != 1) continue;
				for(int l =0; l < (1<<j); l++) swap(split[k][i+l],split[k][i+(1<<j)+l]);}
		}

	bool ans =true;
	for(int i =0; i < N/n; i++) if(split[0][i] != split[1][i]) ans =false;
	cout << (ans?"YES\n":"NO\n");
	return 0;}

// look at my code
// my code is amazing