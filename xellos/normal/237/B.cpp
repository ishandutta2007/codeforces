// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
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
using namespace std::tr1;
	
int main() {
	int N,a;
	scanf(" %d",&N);
	vector< vector<int> > V(N);
	vector<int> T;
	for(int i =0; i < N; i++) {
		scanf(" %d",&a);
		V[i].resize(a);}
	for(int i =0; i < N; i++) for(int j =0; j < V[i].size(); j++) {
		scanf(" %d",&V[i][j]);
		T.push_back(V[i][j]);}
	sort(T.begin(),T.end());
	vector< vector<int> > Vs(N);
	a =0;
	for(int i =0; i < N; i++) {
		for(int j =0; j < V[i].size(); j++) Vs[i].push_back(T[a+j]);
		a +=V[i].size();}
	
	vector< pair< pair<int,int>, pair<int,int> > > sw;
	for(int i =0; i < N; i++) for(int j =0; j < V[i].size(); j++) {
		// is it here?
		if(Vs[i][j] == V[i][j]) continue;
		pair<int,int> p =make_pair(i,j);
		for(int k =0; k < N; k++) for(int l =0; l < V[k].size(); l++) {
			if(p != make_pair(i,j)) break;
			if(V[k][l] == Vs[i][j]) p =make_pair(k,l);}
		swap(V[i][j],V[p.first][p.second]);
		sw.push_back(make_pair(make_pair(i,j),p));}
	printf("%d\n",sw.size());
	for(int i =0; i < sw.size(); i++)
		printf("%d %d %d %d\n",sw[i].first.first+1,sw[i].first.second+1,sw[i].second.first+1,sw[i].second.second+1);
	return 0;}
        
// look at my code
// my code is amazing