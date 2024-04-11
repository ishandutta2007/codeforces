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

int main() {
	int N,a,b;
	cin >> N;
	vector<int> num(N);
	vector<int> P(N);
	for(int i =0; i < N; i++) {
		cin >> num[i];
		P[--num[i]] =i;}

	int Q,typ;
	cin >> Q;
	for(int q =0; q < Q; q++) {
		cin >> typ >> a >> b;
		if(typ == 2) {
			swap(num[--a],num[--b]);
			P[num[a]] =a, P[num[b]] =b;}
		else {
			vector< pair<int,int> > B;
			for(int i =a-1; i < b; i++) B.push_back(make_pair(P[i],i));
			int ans =1;
			for(int i =1; i < B.size(); i++) if(B[i].ff < B[i-1].ff) ans++;
			cout << ans << "\n";}
		}
    return 0;}
        
// look at my code
// my code is amazing