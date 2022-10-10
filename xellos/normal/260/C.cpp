// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
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

int main() {
	int N,x;
	scanf(" %d %d",&N,&x);
	vector<int> v(N);
	for(int i =0; i < N; i++) {
		int j =i-x;
		if(j < 0) j +=N;
		scanf(" %d",&v[j]);}
		
	vector<int> A(N);
	A[0] =v[0];
	for(int i =0; i < N-1; i++) A[i+1] =min(A[i],v[i+1]);
	vector<int> B(N+1,OVER9000);
	B[N-1] =v[N-1];
	for(int i =N-1; i > 0; i--) B[i-1] =min(B[i],v[i-1]);
	
	for(int i =0; i < N; i++) {
		// the first box
		// v[i] turns
		// all boxes: -v[i], boxes v[i+1]..v[N-1]: -v[i]-1
		// min(v[0..i])=v[i], min(v[i+1..N-1])>= v[i]+1
		if(A[i] >= v[i] && B[i+1] >= v[i]+1) {
			// print
			long long orig =(long long)N*(long long)v[i]+(N-1-i);
			for(int j =N-x; j < N; j++) {
				if(j > N-x) printf(" ");
				int y =v[j]-v[i];
				if(j > i) y--;
				if(j == i) printf("%I64d",orig);
				else printf("%d",y);}
			for(int j =0; j < N-x; j++) {
				printf(" ");
				int y =v[j]-v[i];
				if(j > i) y--;
				if(j == i) printf("%I64d",orig);
				else printf("%d",y);}
			printf("\n");
			return 0;}}
	return 0;}

// look at my code
// my code is amazing