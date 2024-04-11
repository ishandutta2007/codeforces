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
	int a[3][3];
	for(int i =0; i < 3; i++) for(int j =0; j < 3; j++) cin >> a[i][j];
	for(a[0][0] =1; a[0][0] <= 100000; a[0][0]++) {
		int b[3][3];
		for(int i =0; i < 3; i++) for(int j =0; j < 3; j++) b[i][j] =a[i][j];
		int s =a[0][0]+a[1][0]+a[2][0];
		b[1][1] =s-b[0][1]-b[2][1];
		b[2][2] =s-b[0][2]-b[1][2];
		bool B =true;
		for(int i =0; i < 3; i++) if(b[0][i]+b[1][i]+b[2][i] != s)
			B =false;
		for(int i =0; i < 3; i++) if(b[i][0]+b[i][1]+b[i][2] != s)
			B =false;
		if(b[0][0]+b[1][1]+b[2][2] != s) B =false;
		if(b[0][2]+b[1][1]+b[2][0] != s) B =false;
		if(b[1][1] <= 0 || b[1][1] > 100000) B =false;
		if(b[2][2] <= 0 || b[2][2] > 100000) B =false;
		if(B) {
			for(int i =0; i < 3; i++) printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
			return 0;}}
	return 0;}

// look at my code
// my code is amazing