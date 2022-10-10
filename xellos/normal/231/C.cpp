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
	int N,K;
	scanf(" %d %d",&N,&K);
	vector<int> V(N);
	for(int i =0; i < N; i++) scanf(" %d",&V[i]);
	sort(V.begin(),V.end());
	
	int j =N-1, o =0;
	int ans =1, ansN =OVER9000;
	for(int i =N-1; i >= 0; i--) {
		while(j > 0) {
			if(V[i]-V[j-1]+o <= K) {
				o +=V[i]-V[j-1];
				j--;}
			else break;}
		ans =max(ans,i-j+1);
		if(ans == i-j+1) ansN =V[i];
		if(i > 0) o -=(i-j)*(V[i]-V[i-1]);}
	printf("%d %d\n",ans,ansN);
	return 0;}
        
// look at my code
// my code is amazing