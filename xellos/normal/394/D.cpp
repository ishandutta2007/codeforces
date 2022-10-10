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

bool check(int D, int N, vector<int> &A) {
	for(int i =0; i < N; i++) {
		int K_min =0, K_max =OVER9000;
		for(int j =i+1; j < N; j++) {
			K_min =max(K_min,(A[j]-A[i])/(j-i)+(int)((A[j]-A[i])%(j-i) != 0));
			K_max =min(K_max,(2*D+A[j]-A[i])/(j-i));}
		for(int j =i-1; j >= 0; j--) {
			K_min =max(K_min,(A[i]-A[j]-2*D)/(i-j)+(int)((A[i]-A[j]-2*D)%(i-j) != 0));
			K_max =min(K_max,(A[i]-A[j])/(i-j));}
		if(K_min <= K_max) return true;}
	return false;}

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(A.begin(),A.end());

	int ansA =-1, ansB =tisic*1000;
	while(ansA < ansB-1) {
		int ansC =(ansA+ansB)/2;
		if(check(ansC,N,A)) ansB =ansC;
		else ansA =ansC;}
	cout << ansB << "\n";

	int D =ansB;
	for(int i =0; i < N; i++) {
		int K_min =0, K_max =OVER9000;
		for(int j =i+1; j < N; j++) {
			K_min =max(K_min,(A[j]-A[i])/(j-i)+(int)((A[j]-A[i])%(j-i) != 0));
			K_max =min(K_max,(2*D+A[j]-A[i])/(j-i));}
		for(int j =i-1; j >= 0; j--) {
			K_min =max(K_min,(A[i]-A[j]-2*D)/(i-j)+(int)((A[i]-A[j]-2*D)%(i-j) != 0));
			K_max =min(K_max,(A[i]-A[j])/(i-j));}
		if(K_min <= K_max) {
			cout << A[i]-D-i*K_min << " " << K_min << "\n";
			return 0;}
		}
	return 0;}

// look at my code
// my code is amazing