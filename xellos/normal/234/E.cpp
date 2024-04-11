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
	int N,x,a,b,c;
	FILE * in =fopen("input.txt","r");
	FILE * out =fopen("output.txt","w");
	fscanf(in," %d %d %d %d %d\n",&N,&x,&a,&b,&c);
	vector< pair<int,string> > V(N);
	for(int i =0; i < N; i++) {
		char C[42];
		fscanf(in,"%s ",C);
		fscanf(in,"%d\n",&V[i].first);
		V[i].second =(string)C;}
	sort(V.begin(),V.end());
	vector< vector<string> > W(4);
	for(int i =3; i >= 0; i--) for(int j =N/4-1; j >= 0; j--) W[3-i].push_back(V[i*(N/4)+j].second);
	
	vector< vector<string> > A(N/4);
	for(int i =0; i < N/4; i++) for(int j =0; j < 4; j++) {
		x =(x*a+b)%c;
		A[i].push_back(W[j][x%(N/4-i)]);
		W[j].erase(W[j].begin()+x%(N/4-i));}

	for(int i =0; i < N/4; i++) {
		fprintf(out,"Group %c:\n",'A'+i);
		for(int j =0; j < 4; j++) fprintf(out,"%s\n",A[i][j].c_str());}
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing