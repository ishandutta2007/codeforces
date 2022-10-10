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
	FILE * in =fopen("input.txt","r");
	FILE * out =fopen("output.txt","w");
	fscanf(in," %d %d",&N,&K);
	vector< pair<int,int> > V(N);
	for(int i =0; i < N; i++) {
		fscanf(in," %d",&V[i].first);
		V[i].second =i+1;}
	sort(V.begin(),V.end());
	fprintf(out,"%d\n",V[N-K].first);
	for(int i =N-1; i >= N-K; i--) {
		if(i < N-1) fprintf(out," ");
		fprintf(out,"%d",V[i].second);}
	fprintf(out,"\n");
	
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing