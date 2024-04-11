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
#define dibs reserve
#define OVER9000 12345678901234567LL
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
	
	priority_queue< pair<long long,int>, vector< pair<long long,int> >, greater< pair<long long,int> > > q; // podcikania
	
	int N;
	cin >> N;
	vector<long long> A(N);
	vector<long long> B(N);
	for(int i =0; i < N; i++) cin >> A[i];
	for(int i =0; i < N; i++) cin >> B[i];
	vector<long long> C(N,OVER9000);
	C[0] =0;
	
	vector<int> Prev(N);
	vector<bool> live(N,true);
	for(int i =0; i < N; i++) Prev[i] =i-1;
	int best =0;
	
	for(int i =1; i < N; i++) {
		// C[i] == min_{j < i}(C[j]+A[i]B[j])
		// update podcikania
		while(!q.empty()) {
			pair<long long,int> p =q.top();
			if(!live[p.ss]) {
				q.pop();
				continue;}
			if(p.ff > A[i]) break;
			q.pop();
			live[Prev[p.ss]] =false;
			Prev[p.ss] =Prev[Prev[p.ss]];
			if(Prev[p.ss] == -1) best =p.ss;
			else {
				// C[p.ss]+z*B[p.ss] <= C[Prev]+z*B[Prev]
				long long x =C[p.ss]-C[Prev[p.ss]];
				long long y =B[Prev[p.ss]]-B[p.ss];
				// x <= z*y
				long long z =x/y;
				if(z*y < x) z++;
				q.push(make_pair(z,p.ss));}
			}
		// pouzi najmensiu
		C[i] =C[best]+A[i]*B[best];
		// pridaj novu
		long long x =C[i]-C[i-1];
		long long y =B[i-1]-B[i];
		long long z =x/y;
		if(z*y < x) z++;
		q.push(make_pair(z,i));}
	
	cout << C[N-1] << "\n";
    return 0;}
        
// look at my code
// my code is amazing