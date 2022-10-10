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
	int N,h,m;
	scanf(" %d",&N);
	int cF =0,cFa =0;
	pair<int,int> l =make_pair(-1,-1);
	for(int i =0; i < N; i++) {
		scanf(" %d %d",&h,&m);
		if(l == make_pair(h,m)) cFa++;
		else {
			l =make_pair(h,m);
			cF =max(cF,cFa);
			cFa =1;}}
	cF =max(cF,cFa);
	printf("%d\n",cF);
	return 0;}
        
// look at my code
// my code is amazing