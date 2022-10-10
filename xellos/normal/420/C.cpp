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
#define OVER9000 1234567890123456780LL
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
	fin(int N) {T.resize(N+patkan,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,P;
	cin >> N >> P;
	long long ans =0;
	vector<int> D(N,0);
	map< pair<int,int>, int > chS;
	vector< pair<int,int> > ch(N);
	for(int i =0; i < N; i++) {
		cin >> ch[i].ff >> ch[i].ss;
		if(ch[i].ff > ch[i].ss) swap(ch[i].ff,ch[i].ss);
		D[--ch[i].ff]++;
		D[--ch[i].ss]++;
		chS[ch[i]] +=1;}
	vector<int> blbe(N,0);

	ALL_THE(chS,it) {
		int x =D[(it->ff).ff]+D[(it->ff).ss]-it->ss;
		if(D[(it->ff).ff]+D[(it->ff).ss] >= P) blbe[(it->ff).ff]++;
		if(x >= P) ans++;}

	fin F(2*N);
	for(int i =N-1; i >= 0; i--) {
		ans +=F.get(D[i]-P+N)-blbe[i];
		F.put(-D[i]+N,1);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing