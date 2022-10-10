// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N;
	scanf(" %d",&N);
	set<int> S;
	vector< pair<int,int> > E(N);
	vector<int> pre_in;
	for(int i =0; i < N; i++) {
		char ch[10];
		int id;
		scanf(" %s %d",ch,&id);
		if(ch[0] == '+') E[i].ff =0;
		else E[i].ff =1;
		E[i].ss =id;
		if(E[i].ff == 0) S.insert(E[i].ss);
		else {
			if(S.find(E[i].ss) == end(S)) pre_in.push_back(E[i].ss);
			S.erase(E[i].ss);}
		}
	S.clear();
	ALL_THE(pre_in,it) S.insert(*it);
	int ans =S.size();
	for(int i =0; i < N; i++) {
		if(E[i].ff == 0) S.insert(E[i].ss);
		else S.erase(E[i].ss);
		ans =max(ans,(int)S.size());}
	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing