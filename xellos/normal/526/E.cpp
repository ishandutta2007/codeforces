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
	int N,Q;
	cin >> N >> Q;
	vector<long long> A(N),S(N+1,0);
	for(int i =0; i < N; i++) {
		cin >> A[i];
		S[i+1] =S[i]+A[i];}

	vector<long long> last(1000000+tisic,-1),nxt(1000000+tisic,-1);
	vector<int> ans(1000000+tisic,0);
	for(int q =0; q < Q; q++) {
		long long b; cin >> b;
		if(b >= S[N]) {cout << "1\n"; continue;}
		for(int i =0; i <= N; i++) last[i] =nxt[i] =-1, ans[i] =0;
		last[N-1] =0, nxt[N-1] =N;
		while(last[N-1] < N && A[N-1]+S[last[N-1]+1] <= b) last[N-1]++;
		for(int i =N-2; i >= 0; i--) {
			if(S[N]-S[i] > b) break;
			nxt[i] =N;
			last[i] =last[i+1];
			while(last[i] > 0 && S[N]-S[i]+S[last[i]] > b) last[i]--;}

		for(int i =N-2; i >= 0; i--) if(nxt[i] == -1) {
			nxt[i] =nxt[i+1];
			while(S[nxt[i]]-S[i] > b) nxt[i]--;
			last[i] =last[nxt[i]];}

		int ansF =N;
		for(int i =N-1; i >= 0; i--) {
			ans[i] =ans[nxt[i]]+1;
			if(i <= last[i]) ansF =min(ans[i],ansF);}
		cout << ansF << "\n";}
	return 0;}

// look at my code
// my code is amazing