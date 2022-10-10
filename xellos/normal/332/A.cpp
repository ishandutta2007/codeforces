// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,a =0;
	string s;
	cin >> N >> s;
	for(int i =0; i < s.length(); i +=N) if(i*N >= 3) {
		int x =0;
		for(int j =0; j < 3; j++) x +=1-2*(int)(s[i-j-1] == 'b');
		if(x == 3 || x == -3) a++;}
	cout << a << "\n";
	return 0;}
        
// look at my code
// my code is amazing