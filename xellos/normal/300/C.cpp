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
#define M 1000000007
// mylittlepony
using namespace std;
using namespace std::tr1;

long long Pow(long long a, int p) {
	if(p == 0) return 1;
	if(p%2 == 1) {
		long long x =(Pow(a,p-1)*a)%M;
		if(x < 0) x +=M;
		return x;}
	long long x =Pow(a,p/2);
	x =(x*x)%M;
	if(x < 0) x +=M;
	return x;}

int main() {
	int a,b,N;
	cin >> a >> b >> N;
	vector<long long> fac(N+1,1);
	for(int i =2; i <= N; i++) {
		fac[i] =(fac[i-1]*i)%M;
		if(fac[i] < 0) fac[i] +=M;}
	
	long long ans =0;
	for(int i =0; i <= N; i++) {
		int q =i*a+(N-i)*b;
		bool B =true;
		while(q > 0) {
			if(q%10 != a && q%10 != b) {
				B =false;
				break;}
			q /=10;}
		if(!B) continue;
		long long ansN =(fac[N]*Pow(fac[i],M-2))%M;
		if(ansN < 0) ansN +=M;
		ansN =(ansN*Pow(fac[N-i],M-2))%M;
		if(ansN < 0) ansN +=M;
		ans =(ansN+ans)%M;}
	if(ans < 0) ans +=M;
	cout << ans << endl;
	return 0;}
        
// look at my code
// my code is amazing