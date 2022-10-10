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
	int N,M;
	FILE * in =fopen("input.txt","r");
	FILE * out =fopen("output.txt","w");
	fscanf(in," %d",&N);
	vector<int> D1(N);
	for(int i =0; i < N; i++) fscanf(in," %d",&D1[i]);
	fscanf(in," %d",&M);
	vector<int> D2(M);
	for(int i =0; i < M; i++) fscanf(in," %d",&D2[i]);
	vector<int> D(N+M);
	for(int i =0; i < N; i++) D[i] =D1[i];
	for(int i =0; i < M; i++) D[N+i] =D2[i];
	
	vector< vector<int> > P1a(1);
	int a =N-2,b =M-1, last =N-1;
	P1a[0].push_back(N-1);
	while(a >= 0 || b >= 0) {
		if(a >= 0) if(D1[a] == D[last]) {
			last =a;
			a--;
			P1a[P1a.size()-1].push_back(last);
			continue;}
		if(b >= 0) if(D2[b] == D[last]) {
			last =b+N;
			b--;
			P1a[P1a.size()-1].push_back(last);
			continue;}
		if(a >= 0) {
			last =a;
			a--;}
		else {
			last =b+N;
			b--;}
		P1a.resize(P1a.size()+1);
		P1a[P1a.size()-1].push_back(last);}
	
	vector< vector<int> > P1b(1);
	a =N-1,b =M-2, last =M+N-1;
	P1b[0].push_back(M+N-1);
	while(a >= 0 || b >= 0) {
		if(a >= 0) if(D1[a] == D[last]) {
			last =a;
			a--;
			P1b[P1b.size()-1].push_back(last);
			continue;}
		if(b >= 0) if(D2[b] == D[last]) {
			last =b+N;
			b--;
			P1b[P1b.size()-1].push_back(last);
			continue;}
		if(a >= 0) {
			last =a;
			a--;}
		else {
			last =b+N;
			b--;}
		P1b.resize(P1b.size()+1);
		P1b[P1b.size()-1].push_back(last);}
	
	if((signed)P1a.size()-1+D1[N-1] > (signed)P1b.size()-1+D2[M-1]) {
		swap(D1[N-1],D2[M-1]);
		swap(P1a,P1b);}
	
	for(int i =P1a.size()-1; i >= 0; i--) for(int j =P1a[i].size()-1; j >= 0; j--) {
		if(i == (signed)P1a.size()-1 && j == (signed)P1a[i].size()-1) fprintf(out,"%d",P1a[i][j]+1);
		else fprintf(out," %d",P1a[i][j]+1);}
	fprintf(out,"\n");
	fprintf(out,"%d\n",(signed)P1a.size()-1+D1[N-1]);
	a =0;
	for(int i =P1a.size()-1; i >= 0; i--) {
		a +=P1a[i].size();
		if(D1[N-1] == 0 && i == 0) break;
		if(i < (signed)P1a.size()-1) fprintf(out," ");
		fprintf(out,"%d",a);}
	fprintf(out,"\n");
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing