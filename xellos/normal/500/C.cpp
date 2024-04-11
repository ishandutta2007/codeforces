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
#define OVER9000 223456789012345678LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
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
	int N,M;
	cin >> N >> M;
	vector<int> W(N),first(N,M+1);
	for(int i =0; i < N; i++) cin >> W[i];
	vector<int> A(M);
	for(int i =0; i < M; i++) {
		cin >> A[i];
		A[i]--;
		first[A[i]] =min(first[A[i]],i);}

	vector<int> seq;
	vector<bool> inSeq(N,false);
	while(true) {
		int x =M+1, y =-1;
		for(int i =0; i < N; i++) if(!inSeq[i] && first[i] <= M && first[i] < x) {
			x =first[i];
			y =i;}
		if(y == -1) break;
		inSeq[y] =true;
		seq.push_back(y);}

	int ans =0;
	for(int i =0; i < M; i++) {
		for(int j =0; j < seq.size(); j++) {
			if(seq[j] == A[i]) {
				seq.erase(seq.begin()+j);
				break;}
			ans +=W[seq[j]];}
		seq.insert(seq.begin(),A[i]);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing