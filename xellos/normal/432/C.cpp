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

	vector<int> P;
	vector<bool> isP(100000+tisic,true);
	isP[0] =isP[1] =false;
	for(int i =2; i <= 100000; i++) if(isP[i]) {
		P.push_back(i);
		for(int j =i; j <= 100000/i; j++) isP[i*j] =false;}
	vector<int> st(100000+tisic,10), ako(100000+tisic,-1);
	st[1] =0;
	int a =0;
	for(int i =2; i <= 100000; i++) {
		while(a+1 < P.size() && P[a+1]-1 <= i) a++;
		for(int j =0; j <= min(a,100); j++) if(st[i] > st[i-P[a-j]+1]+1) {
			ako[i] =P[a-j]-1;
			st[i] =st[i-P[a-j]+1]+1;}
		for(int j =0; j < min(a,100); j++) if(st[i] > st[i-P[j]+1]+1) {
			ako[i] =P[j]-1;
			st[i] =st[i-P[j]+1]+1;}
		}

	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector< pair<int,int> > op;
	for(int i =0; i < N; ) {
		if(A[i] == i+1) {
			i++;
			continue;}
		int d =A[i]-i, x =i;
		while(d > 1) {
			op.push_back(make_pair(x,x+ako[d]));
			swap(A[x],A[x+ako[d]]);
			x +=ako[d];
			d -=ako[d];}
		}

	cout << op.size() << "\n";
	for(int i =0; i < op.size(); i++) cout << op[i].ff+1 << " " << op[i].ss+1 << "\n";
	return 0;}

// look at my code
// my code is amazing