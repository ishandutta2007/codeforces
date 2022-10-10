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
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int K;
	long long L,R;
	cin >> L >> R >> K;
	if(K >= 4 && R-L+1 >= 8) {
		cout << "0\n4\n";
		long long A =L-L%4;
		if(A < L) A +=4;
		cout << A << " " << A+1 << " " << A+2 << " " << A+3 << "\n";
		return 0;}

	if(K == 1 || R == L) {
		cout << L << "\n" << "1\n" << L << "\n";
		return 0;}

	if(K == 2) {
		if(R-L+1 >= 3) {
			cout << "1\n2\n";
			if(L%2 == 0) cout << L << " " << L+1 << "\n";
			else cout << L+1 << " " << L+2 << "\n";
			return 0;}
		if((L^R) > L) cout << L << "\n1\n" << L << "\n";
		else cout << (L^R) << "\n2\n" << L << " " << R << "\n";
		return 0;}

	if(R-L+1 < 8) {
		vector<long long> V(R-L+1);
		for(long long i =0; i <= R-L; i++) V[i] =L+i;
		long long ans =L;
		vector<long long> A(1,L);
		for(int i =1; i < (1<<(R-L+1)); i++) {
			long long x =0;
			vector<long long> B;
			for(long long j =0; j <= R-L; j++) if((i>>j)&1) {
				x =x^V[j];
				B.push_back(V[j]);}
			if(x < ans && B.size() <= K) {
				ans =x;
				A =B;}}
		cout << ans << "\n" << A.size() << "\n";
		for(uint i =0; i < A.size(); i++) cout << A[i] << ((i+1 == A.size())?"\n":" ");
		return 0;}

	// K == 3
	for(int i =50; i >= 0; i--) if((R>>i)&1LL) {
		if((L>>i)&1LL) break;
		for(int j =50; j >= 0; j--) if((L>>j)&1LL) {
			long long A =(1LL<<j)^(1LL<<i);
			if(A <= R && A >= L && (A^L) <= R && (A^L) >= L && (A^L) != L && A != L && (A^L) != A) {
				cout << "0\n3\n";
				cout << A << " " << L << " " << (A^L) << "\n";
				return 0;}
			break;}
		break;}
	cout << "1\n2\n" << L-L%2+2 << " " << L-L%2+3 << "\n";
	return 0;}

// look at my code
// my code is amazing