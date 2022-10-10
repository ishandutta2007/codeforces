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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-11
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector< pair<long long,long long> > A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i].ff;
		A[i].ss =i;}
	sort(A.begin(),A.end());
	int K;
	cin >> K;

	vector<long long> S(N+1,0);
	for(int i =0; i < N; i++) S[i+1] =S[i]+A[i].ff;

	long long ansS =0, aktS =0, ansX =0;
	for(int i =0; i < K; i++) ansS +=A[i].ff-S[i];
	aktS =ansS;
	for(int i =1; i <= N-K; i++) {
		aktS -=S[i+K-1]-S[i]-A[i-1].ff*(K-1);
		aktS +=A[i+K-1].ff*(K-1)-(S[i+K-1]-S[i]);
		if(aktS < ansS) {
			ansS =aktS;
			ansX =i;}
		}

	for(int i =0; i < K; i++) cout << A[ansX+i].ss+1 << ((i == K-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing