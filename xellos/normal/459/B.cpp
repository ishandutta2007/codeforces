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
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(A.begin(),A.end());
	cout << A[N-1]-A[0] << " ";
	if(A[N-1] == A[0]) {
		cout << 1LL*N*(N-1)/2 << "\n";
		return 0;}
	int a =0, b =0;
	for(int i =0; i < N; i++) if(A[i] == A[0]) a++;
	for(int i =0; i < N; i++) if(A[i] == A[N-1]) b++;
	cout << 1LL*a*b << "\n";
	return 0;}

// look at my code
// my code is amazing