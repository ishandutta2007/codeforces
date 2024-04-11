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

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin.sync_with_stdio(0);
	int N,K;
	cin >> N >> K;
	if(K == 0) {
		for(int i =0; i < 2*N; i++) cout << i+1 << ((i == 2*N-1)?"\n":" ");
		return 0;}
		
	cout << "1 " << K+1;
	int a =2, b =2*N;
	if(a == K+1) a++;
	if(b == K+1) b--;
	for(int i =1; i < N; i++) {
		cout << " " << b << " " << a;
		a++, b--;
		if(a == K+1) a++;
		if(b == K+1) b--;}
	cout << "\n";
	return 0;}
	
// look at my code
// my code is amazing