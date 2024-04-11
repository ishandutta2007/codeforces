// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
using namespace std::tr1;

int gcd(int a, int b) {
	if(a > b) swap(a,b);
	if(a == 0) return b;
	return gcd(b%a,a);}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	
	vector< vector<int> > GCDr(20, vector<int>(N,1));
	for(int i =N-1; i >= 0; i--) {
		GCDr[0][i] =A[i];
		for(int j =1; j < 20; j++) {
			if(i+(1<<j)-1 < N) GCDr[j][i] =gcd(GCDr[j-1][i],GCDr[j-1][i+(1<<(j-1))]);
			else break;}
		}
	
	vector< vector<int> > GCDl(20, vector<int>(N,1));
	for(int i =0; i < N; i++) {
		GCDl[0][i] =A[i];
		for(int j =1; j < 20; j++) {
			if(i-(1<<j)+1 >= 0) GCDl[j][i] =gcd(GCDl[j-1][i],GCDl[j-1][i-(1<<(j-1))]);
			else break;}
		}
	
	vector<int> ans(N);
	vector<int> L(N);
	for(int i =0; i < N; i++) {
		int l =i, k =19;
		while(k > 0) {
			if(l-(1<<k)+1 < 0) {
				k--; 
				continue;}
			if(GCDl[k][l]%A[i] != 0) {
				k--;
				continue;}
			l -=(1<<k)-1;}
		int r =i; k =19;
		while(k > 0) {
			if(r+(1<<k)-1 >= N) {
				k--; 
				continue;}
			if(GCDr[k][r]%A[i] != 0) {
				k--;
				continue;}
			r +=(1<<k)-1;}
		L[i] =l;
		ans[i] =r-l;}
	
	int a =0;
	for(int i =0; i < N; i++) a =max(a,ans[i]);
	set<int> B;
	for(int i =0; i < N; i++) if(ans[i] == a) B.insert(L[i]+1);
	cout << (int)B.size() << " " << a << "\n";
	ALL_THE(B,it) {
		if(it != B.begin()) cout << " ";
		cout << *it;}
	cout << "\n";
	return 0;}
        
// look at my code
// my code is amazing