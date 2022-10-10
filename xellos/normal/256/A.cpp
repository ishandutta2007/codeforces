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
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;

int main() {
	int N,x =0;
	scanf(" %d",&N);
	vector<int> V(N);
	for(int i =0; i < N; i++) scanf(" %d",&V[i]);
	
	vector< vector<int> > ans(N);
	map<int,int> M;
	for(int i =0; i < N; i++) M[V[i]] =0;
	for(map<int,int>::iterator it =M.begin(); it != M.end(); it++) {
		M[(*it).first] =x;
		x++;}
	
	vector< set<int> > S(N);
	x =1;
	for(int i =0; i < N; i++) {
		ans[i].resize(N,1);
		int y =i, z =M[V[i]];
		for(int j =i-1; j >= 0; j--) {
			while(y >= 0) {
				if(V[i] == V[y] && y < j) break;
				else y--;}
			if(y < 0) ans[i][j] =2;
			else {
				set<int>::iterator it =S[M[V[j]]].lower_bound(y);
				if(it == S[M[V[j]]].begin()) ans[i][j] =3;
				else {
					it--;
					ans[i][j] =ans[y][*it]+2;}}
			x =max(x,ans[i][j]);}
		S[z].insert(i);}
	printf("%d\n",x);
	return 0;}

// look at my code
// my code is amazing