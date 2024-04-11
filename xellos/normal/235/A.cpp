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
	
long long gcd(long long x, long long y) {
	if(x > y) swap(x,y);
	if(x == 0) return y;
	return gcd(y%x,x);}

long long lcm(long long x, long long y) {
	return x*y/gcd(x,y);}

int main() {
	long long N;
	scanf(" %I64d",&N);

	vector<long long> V;
	for(long long i =N-1; i >= 1; i--) if(gcd(N,i) == 1) V.push_back(i);
	
	long long M =1;
	for(int i =0; i < (signed)V.size(); i++) for(int j =i; j < (signed)V.size(); j++) {
		if(gcd(V[i],V[j]) == 1) M =max(M,N*V[i]*V[j]);
		if(N*V[i]*V[j] < M) break;}

	if(N > 2) M =max(M,N*(N-1)*(N-2)/2);
	if(N > 3) M =max(M,lcm(N-1,lcm(N-2,N-3)));
	printf("%I64d\n",M);
	
	return 0;}
        
// look at my code
// my code is amazing