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
	string s;
	for(int i =0; i < 8; i++) {
		cin >> s;
		for(int j =0; j < 8; j++) if(s[j] == s[(j+1)%8]) {
			printf("NO\n");
			return 0;}}
	printf("YES\n");
	return 0;}

// look at my code
// my code is amazing