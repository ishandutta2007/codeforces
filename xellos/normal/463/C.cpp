// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< vector<int> > A(N,vector<int>(N,0));
	for(int i =0; i < N*N; i++) cin >> A[i/N][i%N];

	vector<long long> D1(2*N-1,0),D2(2*N-1,0);
	for(int i =0; i < 2*N-1; i++) for(int j =-3*N-tisic; j < 3*N+tisic; j++) if((i+j)%2 == 0) {
		int x =(i+j)/2, y =(i-j)/2;
		if(x >= 0 && y >= 0 && x < N && y < N) D1[i] +=A[x][y], D2[j+N-1] +=A[x][y];
		}

	long long a =0, b =0;
	for(int i =0; i < N; i++) for(int j =0; j < N; j++) {
		if((i+j)%2 == 0) a =max(a,D1[i+j]+D2[i-j+N-1]-A[i][j]);
		else b =max(b,D1[i+j]+D2[i-j+N-1]-A[i][j]);}
	cout << a+b << "\n";
	bool ok =false;
	for(int i =0; i < N; i++) if(!ok) for(int j =0; j < N; j++)
		if((i+j)%2 == 0 && a == D1[i+j]+D2[i-j+N-1]-A[i][j]) {
			cout << i+1 << " " << j+1 << " ";
			ok =true;
			break;}
	ok =false;
	for(int i =0; i < N; i++) if(!ok) for(int j =0; j < N; j++)
		if((i+j)%2 != 0 && b == D1[i+j]+D2[i-j+N-1]-A[i][j]) {
			cout << i+1 << " " << j+1 << "\n";
			ok =true;
			break;}
	return 0;}

// look at my code
// my code is amazing