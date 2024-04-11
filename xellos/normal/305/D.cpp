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
#define dibs reserve
#define OVER9000 123456789012345678LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
#define exit() {printf("0\n"); return 0;}
#define mod 1000000007
// mylittlepony
using namespace std;

int main() {
	int N,M,K,a,b;
	scanf(" %d %d %d",&N,&M,&K);
	vector< vector<int> > adjL(N);
	for(int i =0; i < M; i++) {
		cin >> a >> b;
		adjL[--a].push_back(--b);}
	vector<bool> bs(N,false);
	for(int i =0; i < N; i++) {
		if(adjL[i].size() > 2) exit();
		ALL_THE(adjL[i],it) {
			if(*it > i+1 && *it != i+K+1) exit();
			if(*it == i+K+1) bs[i] =true;}}
	
	vector<int> pow(K+1,1);
	for(int i =1; i <= K; i++) {
		pow[i] =(pow[i-1]*2)%mod;
		if(pow[i] < 0) pow[i] +=mod;}
	
	int ans =0, n =0;
	a =b =-1;
	for(int i =0; i < N; i++) if(bs[i]) {
		n++;
		if(a == -1) a =i;
		else b =i;}
	if(b > a+K) exit();
	if(a == -1) {
		ans =1;
		for(int i =0; i < N-1-K; i++) {
			ans =(ans+pow[min(K,N-2-K-i)])%mod;
			if(ans < 0) ans +=mod;}
		printf("%d\n",ans);
		return 0;}
	
//	cout << a << b << endl;	
	for(int i =max(0,b-K); i < min(N-1-K,a); i++) {
		ans =(ans+pow[min(K,N-2-K-i)-n])%mod;
		if(ans < 0) ans +=mod;}
	ans =(ans+pow[min(K,N-2-K-a)-n+1])%mod;
	if(ans < 0) ans +=mod;
	printf("%d\n",ans);
	return 0;}
        
// look at my code
// my code is amazing