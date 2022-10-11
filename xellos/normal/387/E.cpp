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

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+1,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i]++;
		}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	int N,K;
	cin >> N >> K;
	vector<int> X(N), Y(K);
	for(int i =0; i < N; i++) cin >> X[i];
	for(int i =0; i < K; i++) cin >> Y[i];
	int a =0;
	vector<bool> B(N,false);
	for(int i =0; i < K; i++) {
		while(a < N && X[a] != Y[i]) a++;
		if(a < N) B[a] =true;}

	vector< pair<int,int> > A(N);
	for(int i =0; i < N; i++) {
		A[i].ss =i;
		A[i].ff =X[i];}
	sort(A.begin(),A.end());

	map<int,int> M;
	M[0] =N-1;
	long long ans =0;
	fin F(N);

	for(int i =0; i < N; i++) {
		auto it =M.upper_bound(A[i].ss); it--;
		if(!B[A[i].ss]) {
			ans +=(it->ss)-(it->ff)+1-F.get(it->ss)+F.get(it->ff-1);
			F.put(A[i].ss);
			continue;}
		if(A[i].ss != it->ss) M[A[i].ss+1] =it->ss;
		if(A[i].ss != it->ff) M[it->ff] =A[i].ss-1;
		else M.erase(it);
		F.put(A[i].ss);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing