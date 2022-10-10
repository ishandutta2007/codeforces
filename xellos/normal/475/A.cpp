// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int K;
	cin >> K;
	string s[] ={
		"+------------------------+",
		"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
		"|#.#.#.#.#.#.#.#.#.#.#.|.|",
		"|#.......................|",
		"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
		"+------------------------+"};
	while(K > 0) {
		bool ok =false;
		for(uint j =0; j < s[0].length(); j++) if(!ok) for(int i =0; i < 5; i++) if(s[i][j] == '#') {
			ok =true;
			s[i][j] ='O';
			break;}
		K--;}

	for(int i =0; i < 6; i++) cout << s[i] << "\n";
	return 0;}

// look at my code
// my code is amazing