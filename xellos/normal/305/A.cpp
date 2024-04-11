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
#define OVER9000 123456789012345678LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
#define exit() {printf("0\n"); return 0;}
#define mod 1000000007
// mylittlepony
using namespace std;

int main() {
	int N,a;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for(int i =0; i < N; i++) {
		cin >> A[i];
		a =A[i];
		int b =0;
		for(int j =0; j < 3; j++) {
			b =((a%10 == 0)?0:1)+2*b;
			a /=10;}
		B[i] =b;}
	
	int ans =0;
	for(int i =0; i < N; i++) if(A[i] == 0) ans++;
	for(int i =0; i < N; i++) for(int j =0; j < N; j++) for(int k =0; k < N; k++) 
		if(A[i] > 0 && A[j] > 0 && A[k] > 0)
			if(((B[i]&B[j])|(B[i]&B[k])|(B[j]&B[k])) == 0) {
				cout << ans+3 << "\n";
				cout << A[i] << " " << A[j] << " " << A[k] << ((ans > 0)?" ":"");
				for(int l =0; l < N; l++) if(A[l] == 0) {
					ans--;
					cout << "0" << ((ans > 0)?" ":"\n");}
				return 0;}
	for(int i =0; i < N; i++) for(int j =0; j < N; j++)
		if(A[i] > 0 && A[j] > 0)
			if((B[i]&B[j]) == 0) {
				cout << ans+2 << "\n";
				cout << A[i] << " " << A[j] << ((ans > 0)?" ":"");
				for(int l =0; l < N; l++) if(A[l] == 0) {
					ans--;
					cout << "0" << ((ans > 0)?" ":"\n");}
				return 0;}
	for(int i =0; i < N; i++) if(A[i] > 0) {
		cout << ans+1 << "\n";
		cout << A[i] << ((ans > 0)?" ":"");
		for(int l =0; l < N; l++) if(A[l] == 0) {
			ans--;
			cout << "0" << ((ans > 0)?" ":"\n");}
		return 0;}
	cout << ans << endl;
	for(int l =0; l < N; l++) if(A[l] == 0) {
		ans--;
		cout << "0" << ((ans > 0)?" ":"\n");}
	return 0;}
        
// look at my code
// my code is amazing