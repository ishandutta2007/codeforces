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
	
vector< pair< vector<int>, vector<int> > > sched(int N, vector<int> H) {
	vector< pair< vector<int>, vector<int> > > ret;
	if(N <= 1) return ret;
	vector<int> h1;
	for(int i =0; i < N/2; i++) h1.push_back(H[i]);
	vector<int> h2;
	for(int i =N/2; i < N; i++) h2.push_back(H[i]);
	vector< pair< vector<int>, vector<int> > > r1 =sched(N/2,h1);
	ret =sched(N-N/2,h2);
	for(int i =0; i < (signed)r1.size(); i++) {
		for(int j =0; j < (signed)r1[i].first.size(); j++) ret[i].first.push_back(r1[i].first[j]);
		for(int j =0; j < (signed)r1[i].second.size(); j++) ret[i].second.push_back(r1[i].second[j]);}
	ret.push_back(make_pair(h1,h2));
	return ret;}
	
int main() {
	int N;
	FILE * in =fopen("input.txt","r");
	FILE * out =fopen("output.txt","w");
	fscanf(in," %d\n",&N);
	
	vector<int> ans(N+1,0);
	ans[2] =1;
	ans[1] =ans[0] =0;
	for(int i =3; i <= N; i++) ans[i] =max(ans[i/2],ans[i-i/2])+1;
	fprintf(out,"%d\n",ans[N]);

	vector<int> V(N);
	for(int i =0; i < N; i++) V[i] =i+1;
	vector< pair< vector<int>, vector<int> > > Ans =sched(N,V);
	for(int i =0; i < (signed)Ans.size(); i++) {
		fprintf(out,"%d",(int)Ans[i].first.size());
		for(int j =0; j < (signed)Ans[i].first.size(); j++) fprintf(out," %d",Ans[i].first[j]);
		fprintf(out,"\n");}
	
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing