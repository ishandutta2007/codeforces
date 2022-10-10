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
#define chocolate win
// mylittlepony
using namespace std;

int main() {
	int N,a,x =0,b;
	cin >> N;
	for(int i =0; i < N; i++) {
		cin >> a >> b;
		if(x+a <= 500) {
			x +=a;
			cout << "A";}
		else {
			x +=a-1000;
			cout << "G";}}
	cout << endl;
	return 0;}

// look at my code
// my code is amazing