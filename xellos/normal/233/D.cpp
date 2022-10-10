// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;
using namespace std::tr1;

long long mult(long long a, long long b) {
	// a**b
	vector<int> V;
	long long c =b;
	while(c > 0) {
		V.push_back(c%2);
		c /=2;}
	long long ret =1;
	while(!V.empty()) {
		ret =(ret*ret)%1000000007;
		if(ret < 0) ret +=1000000007;
		if(V[V.size()-1] == 1) ret =(ret*a)%1000000007;
		if(ret < 0) ret +=1000000007;
		V.pop_back();}
	return ret;}

vector<long long> F;

long long comb(long long N, long long K) {
	if(N < K) return 0;
	long long ret =F[N];
	vector<int> V;
	int m =1000000005;
	while(m > 0) {
		V.push_back(m%2);
		m /=2;}
	long long a =1, b =(F[K]*F[N-K])%1000000007;
	if(b < 0) b +=1000000007;
	while(!V.empty()) {
		a =(a*a)%1000000007;
		if(a < 0) a +=1000000007;
		if(V[V.size()-1] == 1) a =(a*b)%1000000007;
		if(a < 0) a +=1000000007;
		V.pop_back();}
	ret =(ret*a)%1000000007;
	if(ret < 0) ret +=1000000007;
	return ret;}

int main() {
	int N,K;
	long long M;
	scanf(" %d %I64d %d",&N,&M,&K);
	// do prvych i stlpcov dam spolu j bodov, mam moznosti A[i][j]
	// pre celu tabulku sum(A[N-M%N][K-j]**(M/N)*sum(A[M%N][j])**(M/N+1)
	// ako zratam A?
	// A[i][j] == C[i*N][j]
	F.resize(N*N+tisic,1);
	for(int i =2; i <= N*N; i++) {
		F[i] =(F[i-1]*i)%1000000007;
		if(F[i] < 0) F[i] +=1000000007;}

	vector< vector<long long> > B(N);
	for(int i =0; i < N; i++) {
		B[i].resize(N+tisic);
		for(int j =0; j <= N; j++) B[i][j] =mult(comb(N,j),M/N+(long long)(i < M%N));}
	
	vector< vector<long long> > A(N+tisic);
	for(int i =0; i <= N; i++) A[i].resize(N*N+tisic,0);
	A[0][0] =1;
	for(int i =0; i < N; i++) for(int j =0; j <= i*N; j++) {
		for(int k =0; k <= N; k++) {
			A[i+1][j+k] =(A[i+1][j+k]+B[i][k]*A[i][j])%1000000007;
			if(A[i+1][j+k] < 0) A[i+1][j+k] +=1000000007;}}
	printf("%I64d\n",A[N][K]);
	return 0;}
        
// look at my code
// my code is amazing