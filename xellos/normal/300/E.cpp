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
using namespace std::tr1;

long long Mdiv(long long N, int P) {
	if(N <= 1) return 0;
	return (N/(long long)P)+Mdiv(N/(long long)P,P);}

int main() {
	int K,a;
	cin >> K;

	vector<int> dif(10000000+tisic,0);
	for(int i =0; i < K; i++) {
		cin >> a;
		dif[a]++;}
	vector<long long> pow0(10000000+tisic,0);
	a =0;
	for(int i =10000000; i >= 2; i--) dif[i] +=dif[i+1];

	vector<int> V(10000000+tisic);
	for(int i =0; i <= 10000000; i++) V[i] =i;
	vector<int> isP(10000000+tisic,true);
	vector<int> A(10000000+tisic,0);
	for(int i =2; i <= 10000000; i++) if(isP[i])
		for(int j =1; j <= 10000000/i; j++) {
			isP[j*i] =false;
			if(j%i != 0) A[j] =0;
			else A[j] =A[j/i]+1;
			pow0[i] +=(A[j]+1)*dif[i*j];}
/*			if(dif[i*j] > 0)
			while(V[i*j]%i == 0) {
				V[i*j] /=i;
				pow0[i] +=dif[i*j];}}
	for(int i =2; i <= 10000000; i++) {
		if(dif[i] == 0) break;
		if(V[i] > 1) pow0[V[i]] +=dif[i];}
*/	vector< pair<int,long long> > pow;
	for(int i =2; i <= 10000000; i++) if(pow0[i] > 0) pow.push_back(make_pair(i,pow0[i]));
//	cout << ".\n";
	
	long long Na =0, Nb =1000000000000000;
	while(Na < Nb-1) {
		long long Nc =Na/2+Nb/2;
		if(Na%2 == 1 && Nb%2 == 1) Nc++;
//		cout << Na << " " << Nb << endl;
		bool B =true;
		for(auto it =pow.begin(); it != pow.end(); it++)
			if(it->second > Mdiv(Nc,it->first)) {
				B =false;
				break;}
		if(B) Nb =Nc;
		else Na =Nc;}
	cout << Nb << endl;
	return 0;}
        
// look at my code
// my code is amazing