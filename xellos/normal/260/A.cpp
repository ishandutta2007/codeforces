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
	int a,b,n;
	scanf(" %d %d %d",&a,&b,&n);
	for(int i =0; i < 10; i++) if((a*10+i)%b == 0) {
		printf("%d",a*10+i);
		for(int j =1; j < n; j++) printf("0");
		printf("\n");
		return 0;}
	printf("-1\n");
	
	return 0;}

// look at my code
// my code is amazing