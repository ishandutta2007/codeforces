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

int N;
long long mod =1000000007;
vector< vector<int> > son;
vector<long long> P1,P0;
vector<int> C;

long long pw(long long a, long long b, long long mod) {
	if(b <= 0) return 1;
	long long x =pw(a,b/2,mod);
	x =(x*x)%mod;
	if(x < 0) x +=mod;
	if(b%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

void DFS(int R) {
	long long p =1;
	ALL_THE(son[R],it) {
		DFS(*it);
		p =(p*(P0[*it]+P1[*it]))%mod;
		if(p < 0) p +=mod;}

	if(C[R]) {
		P0[R] =0;
		P1[R] =p;}

	else {
		P1[R] =0;
		ALL_THE(son[R],jt) {
			if((P0[*jt]+P1[*jt])%mod == 0) {
				P1[R] =P1[*jt];
				ALL_THE(son[R],it) if(jt != it) {
					P1[R] =(P1[R]*(P0[*it]+P1[*it]))%mod;
					if(P1[R] < 0) P1[R] +=mod;}
				break;}
			P1[R] +=(P1[*jt]*pw(P0[*jt]+P1[*jt],mod-2,mod))%mod;}
		P1[R] %=mod;
		if(P1[R] < 0) P1[R] +=mod;
		P1[R] =(p*P1[R])%mod;
		if(P1[R] < 0) P1[R] +=mod;
		P0[R] =p;}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	C.resize(N);
	son.resize(N);
	for(int i =0; i < N-1; i++) {
		int a;
		cin >> a;
		son[a].push_back(i+1);}
	for(int i =0; i < N; i++) cin >> C[i];
	P1.resize(N);
	P0.resize(N);
	DFS(0);
	cout << P1[0] << "\n";
	return 0;}

// look at my code
// my code is amazing