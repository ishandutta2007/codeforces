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
#define OVER9000 12345678901234567LL
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

struct mat {
	long long M[2][2];};

mat PowM(mat A, long long e, long long mod) {
	if(e <= 0) {
		mat X; X.M[0][0] =X.M[1][1] =1; X.M[0][1] =X.M[1][0] =0;
		return X;}
	mat X =PowM(A,e/2,mod), Y;
	for(int i =0; i < 2; i++) for(int j =0; j < 2; j++) {
		Y.M[i][j] =0;
		for(int k =0; k < 2; k++) Y.M[i][j] +=X.M[i][k]*X.M[k][j];
		Y.M[i][j] %=mod;}
	if(e%2 != 0) {
		mat Z;
		for(int i =0; i < 2; i++) for(int j =0; j < 2; j++) {
			Z.M[i][j] =0;
			for(int k =0; k < 2; k++) Z.M[i][j] +=A.M[i][k]*Y.M[k][j];
			Z.M[i][j] %=mod;}
		return Z;}
	else return Y;}

long long Pow(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	a %=mod;
	long long x =Pow(a,e/2,mod);
	x =(x*x)%mod;
	if(e%2 != 0) x =(x*a)%mod;
	return x;}

long long fib(long long i, long long mod) {
	mat A;
	A.M[0][0] =A.M[0][1] =A.M[1][0] =1;
	A.M[1][1] =0;
	A =PowM(A,i,mod);
	return A.M[0][0];}

int main() {
	cin.sync_with_stdio(0);
	long long N, mod =1000000007;
	int K;
	cin >> N >> K;
	if(N <= 1000) {
		long long ans =0;
		long long F[N+1];
		F[1] =1, F[2] =2;
		for(int i =1; i <= N; i++) {
			if(i > 2) F[i] =(F[i-1]+F[i-2])%mod;
			ans =(ans+F[i]*Pow(i,K,mod))%mod;}
		cout << ans << "\n";
		return 0;}

	long long C[42][42];
	for(int i =0; i <= 40; i++) {
		C[0][i] =0;
		C[i][0] =1;}
	for(int i =1; i <= 40; i++) for(int j =1; j <= 40; j++)
		C[i][j] =(C[i-1][j-1]+C[i-1][j])%mod;

	long long ans[100][42];
	for(int i =0; i < 100; i++) {
		ans[i][0] =fib(N-i+2,mod)-2;
		if(ans[i][0] < 0) ans[i][0] +=mod;}

	for(int i =1; i <= K; i++) for(int j =90; j >= 0; j--) {
		ans[j][i] =(2*fib(N-j,mod)*Pow(N-j,i,mod)+fib(N-j-1,mod)*Pow(N-j-1,i,mod)-1-Pow(2,i,mod))%mod;
		if(ans[j][i] < 0) ans[j][i] +=mod;
		for(int k =0; k < i; k++) {
			ans[j][i] =(ans[j][i]-C[i][k]*ans[j+1][k]-(C[i][k]*Pow(2,i-k,mod))%mod*ans[j+2][k])%mod;
			if(ans[j][i] < 0) ans[j][i] +=mod;}
		}

	cout << ans[0][K] << "\n";
	return 0;}

// look at my code
// my code is amazing