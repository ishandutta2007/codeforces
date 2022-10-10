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
	int N;
	scanf(" %d",&N);
	vector< vector<int> > A(N);
	vector<int> B(N);
	for(int i =0; i < N; i++) {
		scanf(" %d",&B[i]);
		int a =B[i];
		for(int j =0; j < 20; j++) {
			A[i].push_back(a%2);
			a /=2;}}
	
	int ans =0;
	vector<int> maxJ(20,-1);
	vector<int> X(2000000,0);
	vector<int> pow(21,1);
	for(int i =0; i < 20; i++) pow[i+1] =pow[i]*2;
	
	for(int i =0; i < N; i++) {
		for(int j =0; j < 20; j++) if(A[i][j] == 1) maxJ[j] =i;
		
		int x =B[i];
		X[x]++;
		multimap<int,int> M;
		for(int j =0; j < 20; j++) if(maxJ[j] >= 0 && maxJ[j] < i) 
			M.insert(make_pair(maxJ[j],j));
		for(multimap<int,int>::reverse_iterator it =M.rbegin(); it != M.rend(); it++) {
			x +=pow[(*it).second];
			multimap<int,int>::reverse_iterator jt =it;
			jt++;
			if(jt == M.rend()) X[x]++;
			else if((*jt).first != (*it).first) X[x]++;}}
	
	for(int i =0; i < 2000000; i++) if(X[i] > 0) {
		ans++;}
	printf("%d\n",ans);

	return 0;}
        
// look at my code
// my code is amazing