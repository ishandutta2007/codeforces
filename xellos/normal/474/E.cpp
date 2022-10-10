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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define param vector<int>
using namespace std;
// mylittledoge

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] =max(T[i],val);
		}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =max(ret,T[i]);
		return ret;}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	long long D;
	cin >> N >> D;
	map<long long,int> M;
	vector<long long> A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i];
		M[A[i]] =0;
		M[A[i]+D] =0;
		M[A[i]-D] =0;}
	vector<long long> B =A;
	int m =0;
	ALL_THE(M,it) it->ss =m++;

	fin F1(m),F2(m);
	vector<int> ans(N);
	int ansT =0, a =-1;
	for(int i =0; i < N; i++) {
		int x =M[A[i]-D], y =m-M[A[i]+D];
		A[i] =M[A[i]];
		int Lx =F1.get(x), Ly =F2.get(y);
		ans[i] =max(Lx,Ly)+1;
		ansT =max(ansT,ans[i]);
		if(ans[i] == ansT) a =i;
		F1.put(A[i],max(Lx,Ly)+1);
		F2.put(m-A[i],max(Lx,Ly)+1);}

	cout << ansT << "\n";
	vector<int> V(1,a+1);
	for(int i =a-1; i >= 0; i--) if(abs(B[i]-B[a]) >= D && ans[i] == ansT-1) {
		V.push_back(i+1);
		ansT--;
		a =i;}
	reverse(V.begin(),V.end());
	ALL_THE(V,it) cout << ((it == V.begin())?"":" ") << *it;
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing