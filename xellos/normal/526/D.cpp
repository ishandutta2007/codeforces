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
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	string S;
	cin >> N >> K >> S;
	long long mod =1000000009, pw =5;
	vector<long long> Ppw(N+1,1), H(N+1,0);
	for(int i =0; i < N; i++) {
		Ppw[i+1] =(Ppw[i]*pw)%mod;
		if(Ppw[i+1] < 0) Ppw[i+1] +=mod;
		H[i+1] =(H[i]*pw+S[i]-'a'+1)%mod;
		if(H[i+1] < 0) H[i+1] +=mod;}

	vector<bool> ans(N+1,false);
	vector< pair<int,int> > I;
	for(int i =K; i <= N; i +=K) {
		long long h =H[i/K];
		bool ok =true;
		for(int j =0; j < K; j++) if((H[j*(i/K)]*Ppw[i/K]+h-H[(j+1)*(i/K)])%mod != 0) ok =false;
		if(!ok) continue;
		int a =0, b =i/K;
		if(i+b <= N && (H[i]*Ppw[b]+h-H[i+b])%mod == 0) {
			I.push_back(make_pair(i,i+b));
			continue;}
		while(b-a > 1) {
			int c =(a+b)/2;
			if(i+c <= N && (H[i]*Ppw[c]+H[c]-H[i+c])%mod == 0) a =c;
			else b =c;}
		I.push_back(make_pair(i,i+a));}

	int a =0, b =0;
	for(int i =0; i <= N; i++) {
		while(a < I.size() && I[a].ff <= i) {
			b =max(b,I[a].ss);
			a++;}
		if(i <= b) ans[i] =true;}

	for(int i =1; i <= N; i++) cout << (ans[i]?"1":"0");
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing