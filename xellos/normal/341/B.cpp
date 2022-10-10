// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

struct fin {
	vector<int> T;
	
	fin(int N) {T.resize(N+1,0);}
	
	int lastone(int x) {return x&(x^(x-1));}
	
	int get(int pos) {
		int ans =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ans =max(ans,T[i]);
		return ans;}
	
	void upd(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] =max(T[i],val);}
	};

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	
	fin F(N);
	int ans =0;
	for(int i =0; i < N; i++) {
		int x =F.get(A[i]-1)+1;
		F.upd(A[i]-1,x);
		ans =max(ans,x);}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing