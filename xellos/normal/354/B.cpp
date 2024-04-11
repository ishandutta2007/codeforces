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

int main() {
	int N;
	scanf(" %d",&N);
	char ch[100];
	vector<string> A(N);
	for(int i =0; i < N; i++) {
		scanf(" %s",ch);
		A[i] =(string)ch;}

	vector< vector<int> > cid(N,vector<int>(N));
	for(int i =0; i < 2*N-1; i++) {
		int p =0;
		for(int j =0; j < N; j++) if(i-j >= 0 && i-j < N)
			cid[j][i-j] =p++;
		}

	vector<int> resD[50];
	resD[2*N-2].resize(2);
	resD[2*N-2][1] =(A[N-1][N-1] == 'a')?1:((A[N-1][N-1] == 'b')?-1:0);
	for(int i =2*N-3; i >= 0; i--) {
		vector< pair<int,int> > D;
		for(int j =0; j < N; j++) if(i-j >= 0 && i-j < N) D.push_back(make_pair(j,i-j));
		int m =D.size();
		resD[i].resize(1<<m);
		for(int j =1; j < (1<<m); j++) {
			if(i%2 == 0) resD[i][j] =1000;
			else resD[i][j] =-1000;
			vector<int> st2(26,0);
			bool ok =true;
			int c =-1;
			for(int k =0; k < m; k++) if((j>>k)&1) {
				if(c == -1) c =A[D[k].ff][D[k].ss]-'a';
				else if(c != A[D[k].ff][D[k].ss]-'a') {ok =false; break;}
				if(D[k].ff < N-1) st2[A[D[k].ff+1][D[k].ss]-'a'] |=1<<cid[D[k].ff+1][D[k].ss];
				if(D[k].ss < N-1) st2[A[D[k].ff][D[k].ss+1]-'a'] |=1<<cid[D[k].ff][D[k].ss+1];}
			if(!ok) continue;
			int p0 =(c == 0)?1:((c == 1)?-1:0);
			if(i%2 != 0) {
				for(int k =0; k < 26; k++) if(st2[k] > 0) 
				if(st2[k] > 0 && resD[i+1][st2[k]] < 1000) resD[i][j] =max(resD[i][j],p0+resD[i+1][st2[k]]);
				}
			else for(int k =0; k < 26; k++) 
				if(st2[k] > 0 && resD[i+1][st2[k]] > -1000) resD[i][j] =min(resD[i][j],p0+resD[i+1][st2[k]]);
			}
		}

	if(resD[0][1] == 0) printf("DRAW\n");
	else if(resD[0][1] > 0) printf("FIRST\n");
	else printf("SECOND\n");
	return 0;}

// look at my code
// my code is amazing