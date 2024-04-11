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
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

struct info {
	int x,y;
	long long d;};

int main() {
	int N,M,K;
	cin >> N >> M >> K;
	vector<long long> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	vector<info> O(M);
	for(int i =0; i < M; i++) {
		cin >> O[i].x >> O[i].y >> O[i].d;
		O[i].x--;}
	vector<long long> dif(M+1,0);
	for(int i =0; i < K; i++) {
		int a,b;
		cin >> a >> b;
		dif[--a]++;
		dif[b]--;}
	
	long long a =0;
	for(int i =0; i < M; i++) {
		a +=dif[i];
		O[i].d *=a;}
	vector<long long> add(N+1,0);
	for(int i =0; i < M; i++) {
		add[O[i].x] +=O[i].d;
		add[O[i].y] -=O[i].d;}
	a =0;
	for(int i =0; i < N; i++) {
		if(i > 0) cout << " ";
		a +=add[i];
		cout << a+V[i];}
	cout << endl;
	return 0;}
        
// look at my code
// my code is amazing