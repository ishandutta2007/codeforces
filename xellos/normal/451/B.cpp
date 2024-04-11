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
#define OVER9000 1234567890123456780LL
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
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector<int> B =A;
	sort(begin(B),end(B));
	int j =-1, k =N;
	for(int i =0; i < N; i++) if(B[i] != A[i]) {
		j =i;
		break;}
	if(j == -1) {cout << "yes\n1 1\n"; return 0;}
	for(int i =N-1; i >= 0; i--) if(B[i] != A[i]) {
		k =i;
		break;}
	reverse(begin(A)+j,begin(A)+k+1);
	for(int i =0; i < N; i++) if(A[i] != B[i]) {
		cout << "no\n";
		return 0;}
	cout << "yes\n" << j+1 << " " << k+1 << "\n";
	return 0;}

// look at my code
// my code is amazing