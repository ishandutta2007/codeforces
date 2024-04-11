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
#define OVER9000 12345678901234567
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	map<int, pair<int,int> > M;
	for(int i =0; i < N; i++) cin >> A[i];

	vector<long long> S(N+1,0);
	vector<long long> Sn(N+1,0);
	for(int i =0; i < N; i++) {
		S[i+1] =S[i]+A[i];
		Sn[i+1] =Sn[i]+min(0,A[i]);
		auto it =M.find(A[i]);
		if(it == M.end()) M[A[i]] =make_pair(i,i);
		else it->ss.ss =i;}
	
	long long ans =-OVER9000, ansA =0;
	ALL_THE(M,it) if(it->ss.ff != it->ss.ss) {
		long long s =S[it->ss.ss+1]-S[it->ss.ff]-(Sn[it->ss.ss]-Sn[it->ss.ff+1]);
		if(s > ans) {
			ans =s;
			ansA =it->ff;}}
	
	vector<int> cut;
	pair<int,int> I =M[ansA];
	for(int i =0; i < I.ff; i++) cut.push_back(i);
	for(int i =I.ff+1; i < I.ss; i++) if(A[i] < 0) cut.push_back(i);
	for(int i =I.ss+1; i < N; i++) cut.push_back(i);
	
	cout << ans << " " << cut.size() << "\n";
	for(int i =0; i < cut.size(); i++) cout << cut[i]+1 << ((i == cut.size()-1)?"\n":" ");
    return 0;}
        
// look at my code
// my code is amazing