// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N;
	scanf(" %d",&N);
	if(N%2 != 0) {printf("0\n"); return 0;}
	char ch[100000+tisic];
	scanf(" %s",ch);
	vector<bool> V(N);
	for(int i =0; i < N; i++) V[i] =(ch[i] == '?');

	vector<uint> poc(N/2+tisic,0);
	poc[0] =1;
	for(int i =0; i < N; i++) if(V[i]) {
		for(int j =(i+1)/2; j >= 1; j--) poc[j] =poc[j]*25+poc[j-1];
		poc[0] *=25;}

	printf("%u\n",poc[N/2]);
	return 0;}

// look at my code
// my code is amazing