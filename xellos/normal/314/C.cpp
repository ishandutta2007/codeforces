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
#define M 1000000007LL
// mylittlepony
using namespace std;

struct fin {
	vector<long long> T;
	
	fin(int N) {T.resize(N,0);}
	
	int lastone(int x) {return x&(x^(x-1));}
	
	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =(ret+T[i])%M;
		return ret;}
	
	void put(int pos, long long val) {
		for(int i =pos+1; i < (int)T.size(); i +=lastone(i)) T[i] =(T[i]+val)%M;}
	};

int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	map<long long,int> C;
	ALL_THE(A,it) C[*it] =0;
	int a =1;
	ALL_THE(C,it) {
		it->ss =a;
		a++;}
	vector<int> B(N);
	for(int i =0; i < N; i++) B[i] =C[A[i]];
	
	fin F(N+tisic);
	vector<int> last(N+tisic,-1);
	long long ans =0;
	vector<long long> kon(N,0);
	vector<long long> men(N,0);
	for(int i =0; i < N; i++) {
		long long x;
		if(-1 == last[B[i]]) x =F.get(B[i])+1;
		else x =F.get(B[i]-1)+kon[last[B[i]]]-men[last[B[i]]];
		x %=M;
		if(x < M) x +=M;
//		cout << x << "\n";
		men[i] =F.get(B[i]-1);
		x =(x*A[i])%M;
		last[B[i]] =i;
		kon[i] =x;
		F.put(B[i],x);
		ans =(ans+x)%M;}
	cout << ans << "\n";
	return 0;}
        
// look at my code
// my code is amazing