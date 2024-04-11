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
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s,t;
	int N;
	cin >> s >> N;
	vector< pair<int,string> > T(N);
	for(int i =0; i < N; i++) {
		cin >> t;
		T[i].ff =t[0]-'0';
		T[i].ss =t.substr(3,t.length()-2);}

	vector< pair<long long,long long> > dif(10);
	for(int i =0; i < 10; i++) dif[i].ff =10, dif[i].ss =i;
	long long mod =1000000007;

	for(int i =N-1; i >= 0; i--) {
		pair<long long,long long> D;
		D.ff =1, D.ss =0;
		for(int j =0; j < T[i].ss.length(); j++) {
			D.ff =(D.ff*dif[T[i].ss[j]-'0'].ff)%mod;
			D.ss =(D.ss*dif[T[i].ss[j]-'0'].ff+dif[T[i].ss[j]-'0'].ss)%mod;
			if(D.ff < 0) D.ff +=mod;
			if(D.ss < 0) D.ss +=mod;}
		dif[T[i].ff] =D;}

	long long ans =0;
	for(int i =0; i < s.length(); i++) {
		ans =(ans*dif[s[i]-'0'].ff+dif[s[i]-'0'].ss)%mod;
		if(ans < 0) ans +=mod;}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing