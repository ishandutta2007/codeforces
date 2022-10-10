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
	int X,Y,Z;
	scanf(" %d %d %d",&X,&Y,&Z);
	int X1,Y1,Z1;
	scanf(" %d %d %d",&X1,&Y1,&Z1);
	int A[6];
	for(int i =0; i < 6; i++) scanf(" %d",&A[i]);

	int sum =0;
	if(Y < 0) sum +=A[0];
	if(Y > Y1) sum +=A[1];
	if(Z < 0) sum +=A[2];
	if(Z > Z1) sum +=A[3];
	if(X < 0) sum +=A[4];
	if(X > X1) sum +=A[5];
	printf("%d\n",sum);	
	return 0;}
        
// look at my code
// my code is amazing