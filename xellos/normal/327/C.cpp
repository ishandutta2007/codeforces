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
#define OVER9000 234567890
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

long long Pow(long long a, long long e) {
	if(e == 0) return 1;
	long long x =(e%2 == 0)?(Pow(a,e/2)):(Pow(a,e-1));
	if(e%2 == 0) x =(x*x)%1000000007;
	else x =(x*a)%1000000007;
	if(x < 0) x +=1000000007;
	return x;}

int main() {
	string A;
	cin >> A;
	int K;
	cin >> K;
	
	long long ans =0, a =1, b =Pow(2,(long long)A.length());
	long long inv =Pow(b-1,1000000005);
	b =((Pow(b,K)-1)*inv)%1000000007;
//	cout << b << "\n";
	for(int i =0; i < (int)A.length(); i++) {
		if((A[i]-'0')%5 == 0) ans =(ans+b*a)%1000000007;
		a =(a*2)%1000000007;}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing