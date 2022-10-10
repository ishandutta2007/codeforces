// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A((1<<(N+1))-2);
	for(int i =0; i < A.size(); i++) cin >> A[i];
	vector<long long> P(1<<(N+1),0);
	for(int i =(1<<N)-1; i > 0; i--) P[i] =max(P[2*i+1]+A[2*i-1],P[2*i]+A[2*i-2]);
	long long ans =0;
	for(int i =(1<<N)-1; i > 0; i--) ans +=abs(P[2*i+1]+A[2*i-1]-P[2*i]-A[2*i-2]);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing