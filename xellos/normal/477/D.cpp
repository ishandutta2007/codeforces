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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

struct node {
	int son[2];
	int ends;};

struct trie {
	vector<node> V;
	node n0;

	trie() {
		n0.son[0] =n0.son[1] =n0.ends =-1;
		V.dibs(15000000);
		V.resize(1,n0);}

	void put(string s, int x) {
		int L =s.length(), akt =0;
		for(int i =0; i < L; i++) {
			if(V[akt].son[s[i]-'0'] == -1) {
				V[akt].son[s[i]-'0'] =V.size();
				V.push_back(n0);}
			akt =V[akt].son[s[i]-'0'];}
		V[akt].ends =x;}

	void fillStd(int R, vector<int> &v) {
		if(V[R].ends >= 0) v.push_back(V[R].ends);
		for(int i =0; i < 2; i++) if(V[R].son[i] >= 0)
			fillStd(V[R].son[i],v);
		}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int N =s.length();
	int mod =1000000007;

	trie T;
	for(int i =0; i < N; i++) T.put(s.substr(i,N-i),i);
	vector<int> std(1,N);
	T.fillStd(0,std);
	vector<int> SA(N+1);
	for(int i =0; i <= N; i++) SA[std[i]] =i;
//	for(int i =0; i <= N; i++) cout << SA[i] << "\n";
	vector< vector<int> > LCP(N,vector<int>(N+1,0));
	for(int i =N-1; i >= 0; i--) for(int j =i+1; j < N; j++) 
		if(s[i] == s[j]) LCP[i][j] =LCP[i+1][j+1]+1;

	vector< vector<int> > P(N+1,vector<int>(N+1,0));
	vector< vector<int> > S(N+1,vector<int>(N+1,N+tisic));
	P[0][1] =S[0][1] =1;
	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) {
		P[i][j+1] =(P[i][j+1]+P[i][j])%mod;
		S[i][j+1] =min(S[i][j+1],S[i][j]);
		if(j+(j-i) <= N && s[j] == '1' && (LCP[i][j] >= j-i || SA[i] < SA[j])) {
			P[j][j+(j-i)] =(P[j][j+(j-i)]+P[i][j])%mod;
			S[j][j+(j-i)] =min(S[j][j+(j-i)],S[i][j]+1);}
		else if(j+(j-i+1) <= N && s[j] == '1') {
			P[j][j+(j-i)+1] =(P[j][j+(j-i)+1]+P[i][j])%mod;
			S[j][j+(j-i)+1] =min(S[j][j+(j-i)+1],S[i][j]+1);}
		}

	long long ans =0;
	for(int i =0; i < N; i++) ans =(ans+P[i][N])%mod;
	cout << ans << "\n";
	long long ans2 =mod;
	for(int i =N-1; i >= 0; i--) if(S[i][N] < N+tisic) {
		long long a =1, akt =S[i][N];
		for(int j =N-1; j >= i; j--) {
			if(s[j] == '1') akt =(akt+a)%mod;
			a =(a*2)%mod;}
		if(N-i >= 25) {
			if(ans2 != mod) cout << ans2 << "\n";
			else cout << akt << "\n";
			return 0;}
		else ans2 =min(ans2,akt);}
	cout << ans2 << "\n";
	return 0;}

// look at my code
// my code is amazing