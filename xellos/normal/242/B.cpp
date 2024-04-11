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
	scanf(" %d",&N);
	map< pair<int,int>, int > L;
	pair<int,int> p;
	for(int i =0; i < N; i++) {
		scanf(" %d %d",&p.first,&p.second);
		L[p] =i;}
	
	int maxZ =OVER9000, minK =0;
	for(map< pair<int,int>, int >::iterator it =L.begin(); it != L.end(); it++) {
		maxZ =min((*it).first.first,maxZ);
		minK =max((*it).first.second,minK);}
	
	for(map< pair<int,int>, int >::iterator it =L.begin(); it != L.end(); it++) {
		if((*it).first.first == maxZ && (*it).first.second == minK) {
			printf("%d\n",(*it).second+1);
			return 0;}
		}
	printf("-1\n");
	return 0;}
        
// look at my code
// my code is amazing