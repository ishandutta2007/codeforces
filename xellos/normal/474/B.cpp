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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define param vector<int>
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, S =0, a;
	cin >> N;
	map<int,int> M;
	for(int i =0; i < N; i++) {
		cin >> a;
		M[S] =i;
		S +=a;}

	int Q;
	cin >> Q;
	for(int i =0; i < Q; i++) {
		int q;
		cin >> q;
		q--;
		cout << (--M.upper_bound(q))->ss+1 << "\n";}
	return 0;}

// look at my code
// my code is amazing