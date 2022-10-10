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
	int a,b,c;
	scanf(" %d %d %d",&a,&b,&c);
	vector<int> minD(a*b*c+tisic,0);
	for(int i =2; i <= a*b*c; i++) if(minD[i] == 0) {
		minD[i] =i;
		for(int j =2; j <= (a*b*c)/i; j++) if(minD[j*i] == 0) minD[j*i] =i;}
	long long ans =0;
	for(int i =1; i <= a; i++) for(int j =1; j <= b; j++) for(int k =1; k <= c; k++) {
		unordered_map<int,int> M;
		int akt =i*j*k;
		while(akt > 1) {
			M[minD[akt]] =M[minD[akt]]+1;
			akt /=minD[akt];}
		long long ans0 =1;
		for(unordered_map<int,int>::iterator it =M.begin(); it != M.end(); it++) ans0 *=((*it).second+1);
		ans =(ans+ans0)%1073741824;}
	printf("%I64d\n",ans);

	return 0;}
        
// look at my code
// my code is amazing