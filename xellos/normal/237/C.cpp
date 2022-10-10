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
	int A,B,K;
	scanf(" %d %d %d",&A,&B,&K);
	vector<bool> isp(B+tisic,true);
	isp[1] =false;
	for(int i =2; i <= B+tisic-1; i++) if(isp[i])
		for(int j =i; j <= B/i; j++) isp[j*i] =false;
	
	int a =A, cou =0, l =0;
	while(cou < K) {
		if(a+l > B) {
			printf("-1\n");
			return 0;}
		cou +=(int)isp[a+l];
		l++;}
	cou +=(int)isp[a+l]-(int)isp[a];
	a++;
	while(a <= B-l+1) {
		while(cou < K && a+l-1 <= B) {
			cou +=(int)isp[a+l];
			l++;}
		if(a+l-1 > B) break;
		cou +=(int)isp[a+l]-(int)isp[a];
		a++;}
	printf("%d\n",l);

	return 0;}
        
// look at my code
// my code is amazing