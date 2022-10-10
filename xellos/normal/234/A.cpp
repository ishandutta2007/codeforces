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
	char c[420];
	fscanf(in,"%s",c);
	for(int i =0; i < N/2; i++) {
		if('L' == c[N/2+i]) fprintf(out,"%d %d\n",i+N/2+1,i+1);
		else fprintf(out,"%d %d\n",i+1,i+N/2+1);}
	fclose(in);
	fclose(out);
	return 0;}
        
// look at my code
// my code is amazing