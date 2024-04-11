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
	int N,x,a,b;
	FILE * in =fopen("input.txt","r");
	FILE * out =fopen("output.txt","w");
	fscanf(in," %d %d %d\n",&N,&a,&b);
	vector<int> H(N);
	vector<int> S(N);
	for(int i =0; i < N; i++) fscanf(in," %d",&H[i]);
	S[0] =H[0];
	for(int i =1; i < N; i++) S[i] =S[i-1]+H[i];
	
	vector< vector< pair<int,int> > > ans(N); // min. odpoved 
	for(int i =0; i < N; i++) ans[i].resize(a+tisic,make_pair(OVER9000,OVER9000));
	if(H[0] <= a) ans[0][a-H[0]].first =0;
	if(H[0] <= b) ans[0][a].second =0;
	
	for(int i =0; i < N-1; i++) for(int j =0; j <= a; j++) {
		x =min(ans[i][j].first,ans[i][j].second+min(H[i],H[i+1]));
		if(H[i+1] <= j) ans[i+1][j-H[i+1]].first =min(ans[i+1][j-H[i+1]].first,x);
		x =min(ans[i][j].first+min(H[i],H[i+1]),ans[i][j].second);
		if(H[i+1] <= b-(S[i]-(a-j))) ans[i+1][j].second =min(ans[i+1][j].second,x);}

	x =OVER9000;
	for(int i =0; i <= a; i++) x =min(x,ans[N-1][i].first);
	for(int i =0; i <= a; i++) x =min(x,ans[N-1][i].second);
	if(x == OVER9000) x =-1;
	fprintf(out,"%d\n",x);
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing