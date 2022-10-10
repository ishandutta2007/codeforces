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
	int M,N;
	scanf(" %d",&M);
	vector<int> V(M);
	ALL_THE(V,it) scanf(" %d",&(*it));
	sort(V.begin(),V.end());
	scanf(" %d",&N);
	vector<int> W(N);
	ALL_THE(W,it) scanf(" %d",&(*it));
	sort(W.begin(),W.end());
	
	vector<int> S(N+1,0);
	for(int i =0; i < N; i++) S[i+1] =S[i]+W[i];
	
	vector<int> ans(N+tisic,OVER9000);
	ans[0] =0;
	for(int i =0; i < N; i++) {
		for(int j =0; j < 1; j++) {
			if(V[j]+i > N) break;
			ans[V[j]+i] =min(ans[V[j]+i],ans[i]+S[V[j]+i]-S[i]);
			if(V[j]+i+1 <= N) 
				ans[V[j]+i+1] =min(ans[V[j]+i+1],ans[i]+S[V[j]+i+1]-S[i+1]);
			if(V[j]+i+2 <= N) 
				ans[V[j]+i+2] =min(ans[V[j]+i+2],ans[i]+S[V[j]+i+2]-S[i+2]);}
		ans[i+1] =min(ans[i+1],ans[i]+W[i]);}
	printf("%d\n",ans[N]);
	return 0;}

// look at my code
// my code is amazing