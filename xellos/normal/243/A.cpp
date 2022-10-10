// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;

int main() {
	int N,a;
	scanf(" %d",&N);
	vector< queue<int> > V(21);
	vector<int> W(N);
	for(int i =0; i < N; i++) {
		scanf(" %d",&W[i]);
		a =W[i];
		for(int j =0; j <= 20; j++) {
			if(a%2 == 1) V[j].push(i);
			a /=2;}}
	int pow[21];
	pow[0] =1;
	for(int i =0; i <= 20; i++) {
		V[i].push(N);
		if(i > 0) pow[i] =pow[i-1]*2;}
	
	set<int> ans;
	for(int i =0; i < N; i++) {
		multimap<int,int> d;
		for(int j =0; j <= 20; j++) {
			while(V[j].front() < i) V[j].pop();
			d.insert(make_pair(V[j].front(),j));}
		a =0;
		ans.insert(W[i]);
		ALL_THE(d,it) {
			if(it->first == N) break;
			a +=pow[it->second];
			auto jt =it; jt++;
			if(jt == d.end()) ans.insert(a);
			else if(jt->first != it->first) ans.insert(a);}
		ans.insert(a);}
	printf("%d\n",(int)ans.size());
	return 0;}

// look at my code
// my code is amazing