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
using namespace std::tr1;

int abs(int x) {return (x < 0)?(-x):x;}

int main() {
	int N, z =0;
	cin >> N;
	vector<int> V(2*N-1);
	for(int i =0; i < 2*N-1; i++) {
		cin >> V[i];
		if(V[i] < 0) z++;
		if(V[i] < 0) V[i] *=-1;}
	sort(V.begin(),V.end());
	
	queue<int> q;
	q.push(z);
	vector<bool> vis(2*N,false);
	vis[z] =true;
	while(!q.empty()) {
		int a =q.front();
		for(int i =0; i <= min(N,a); i++) if(a-i+(N-i) < 2*N) if(!vis[a-i+(N-i)]) {
			q.push(a-i+(N-i));
			vis[a-i+(N-i)] =true;}
		q.pop();}
	for(int i =0; i < 2*N; i++) if(vis[i]) {
		int s =0;
		for(int j =0; j < i; j++) s -=abs(V[j]);
		for(int j =i; j < 2*N-1; j++) s +=abs(V[j]);
		cout << s << endl;
		return 0;}
    return 0;}
        
// look at my code
// my code is amazing