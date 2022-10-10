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
// kolko je hodin
#define patkan 9
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> P(N);
	vector<bool> F(N,true);
	for(int i =0; i < N; i++) {
		cin >> P[i];
		P[i]--;
		if(P[i] >= 0) F[P[i]] =false;}
	
	int L =0, K =0;
	for(int i =0; i < N; i++) if(P[i] >= 0 && F[i]) L++;
	for(int i =0; i < N; i++) if(F[i] && P[i] < 0) K++;

	long long mod =1000000007;
	vector<long long> fac(N+patkan,1);
	for(int i =0; i <= N+1; i++) {
		fac[i+1] =(fac[i]*(i+1))%mod;
		if(fac[i+1] < 0) fac[i+1] +=mod;}
	vector< vector<long long> > C(N+patkan, vector<long long>(N+patkan,0));
	for(int i =0; i <= N+1; i++) C[i][0] =1;
	for(int i =0; i <= N+1; i++) for(int j =0; j <= N+1; j++) {
		C[i+1][j+1] =(C[i][j]+C[i][j+1])%mod;
		if(C[i+1][j+1] < 0) C[i+1][j+1] +=mod;}

	long long ans =fac[K+L];
	for(int i =1; i <= K; i++) {
		if(i%2 != 0) ans =(ans-fac[K+L-i]*C[K][i])%mod;
		else ans =(ans+fac[K+L-i]*C[K][i])%mod;
		if(ans < 0) ans +=mod;}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing