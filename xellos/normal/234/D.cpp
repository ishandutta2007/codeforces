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
	int M,K,N,a,b;
	FILE * in =fopen("input.txt","r");
	FILE * out =fopen("output.txt","w");
	fscanf(in," %d %d\n",&M,&K);
	set<int> fav;
	for(int i =0; i < K; i++) {
		fscanf(in," %d",&a);
		fav.insert(a);}
	
	fscanf(in," %d\n",&N);
	vector<string> name;
	vector< pair<int,int> > res(N,make_pair(0,0));
	char c[42];
	for(int i =0; i < N; i++) {
		fscanf(in,"%s\n",c);
		name.push_back((string)c);
		fscanf(in," %d",&a);
		int unk =0,favL =K;
		for(int j =0; j < a; j++) {
			fscanf(in," %d",&b);
			if(b == 0) unk++;
			else if(fav.find(b) != fav.end()) {
				favL--;
				res[i].first++;
				res[i].second++;}}
		res[i].first +=min(unk,favL);
		res[i].second +=max(0,unk-(M-a-favL+unk));
		fscanf(in,"\n");}
		
	for(int i =0; i < N; i++) {
		// tento nema byt fav.
		vector<int> V(N);
		for(int j =0; j < N; j++) V[j] =res[j].first;
		V[i] =res[i].second;
		a =b =0;
		for(int j =0; j < N; j++) a =max(a,V[j]);
		if(a > V[i]) b =1;
		// ma byt fav.
		for(int j =0; j < N; j++) V[j] =res[j].second;
		V[i] =res[i].first;
		a =0;
		for(int j =0; j < N; j++) a =max(a,V[j]);
		if(b == 0 && V[i] == a) fprintf(out,"0\n");
		if(b > 0) fprintf(out,"%d\n",b+(int)(V[i] == a));}
		
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing