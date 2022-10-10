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
	FILE * in =fopen("input.txt","r");
	FILE * out =fopen("output.txt","w");
	fscanf(in," %d\n",&N);
	vector<int> T(N);
	vector<int> non(N,0);
	vector<int> nop(N,0);
	for(int i =0; i < N; i++) {
		fscanf(in," %d",&T[i]);
		if(i == 0) non[i] =(int)(T[i] >= 0);
		else non[i] =non[i-1]+(int)(T[i] >= 0);}
	for(int i =N-1; i >= 0; i--) {
		if(i == N-1) nop[i] =(int)(T[i] <= 0);
		else nop[i] =nop[i+1]+(int)(T[i] <= 0);}
	int ans =OVER9000;
	for(int i =0; i < N-1; i++) ans =min(ans,non[i]+nop[i+1]);
	fprintf(out,"%d\n",ans);
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing