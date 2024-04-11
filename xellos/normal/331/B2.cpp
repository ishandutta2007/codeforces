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
// mylittlepony
using namespace std;

struct fin {
	vector<int> T;
	
	fin(int N) {T.resize(N+1,0);}
	
	int lastone(int x) {return x&(x^(x-1));}
	
	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}
	
	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	int N,a,b;
	cin >> N;
	vector<int> num(N);
	vector<int> P(N);
	for(int i =0; i < N; i++) {
		cin >> num[i];
		P[--num[i]] =i;}

	fin F(N); // F[i] == 1 ak P[i] < P[i-1]
	for(int i =1; i < N; i++) if(P[i] < P[i-1]) F.put(i,1);

	int Q,typ;
	cin >> Q;
	for(int q =0; q < Q; q++) {
		cin >> typ >> a >> b;
		if(typ == 2) {
			swap(num[--a],num[--b]);
			if(num[a] > num[b]) swap(a,b);
			// zrus hodnoty pola F
			if(num[a] > 0) if(P[num[a]] < P[num[a]-1]) F.put(num[a],-1);
			if(num[a]+1 < N) if(P[num[a]+1] < P[num[a]]) F.put(num[a]+1,-1);
			if(num[b] > 0 && num[b]-1 != num[a]) if(P[num[b]] < P[num[b]-1]) F.put(num[b],-1);
			if(num[b]+1 < N) if(P[num[b]+1] < P[num[b]]) F.put(num[b]+1,-1);
			P[num[a]] =a, P[num[b]] =b;
			// znovu ich vyrob
			if(num[a] > 0) if(P[num[a]] < P[num[a]-1]) F.put(num[a],1);
			if(num[a]+1 < N) if(P[num[a]+1] < P[num[a]]) F.put(num[a]+1,1);
			if(num[b] > 0 && num[b]-1 != num[a]) if(P[num[b]] < P[num[b]-1]) F.put(num[b],1);
			if(num[b]+1 < N) if(P[num[b]+1] < P[num[b]]) F.put(num[b]+1,1);
			}
		else {
			int ans =1+F.get(b-1)-F.get(a-1);
			cout << ans << "\n";}
		}
    return 0;}
        
// look at my code
// my code is amazing