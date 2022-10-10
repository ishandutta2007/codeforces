// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define exit(x) {cout << x; return 0;}
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	string s;
	cin >> s;
	uint h =0, q =0, fq =OVER9000, L =0;
	for(uint i =0; i < s.length(); i++) {
		if(s[i] == 'H') h++;
		else {
			q++;
			fq =min(fq,i);}}
	if(fq == OVER9000) exit("Yes\n");

	for(uint i =0; i*i <= s.length(); i++) if(i*i == q && h%(1+i) == 0) {
		q =i;
		L =i+h/(1+i);
		break;}
	if(L == 0 || fq%2 == 1) exit("No\n");
	
	string prog =s.substr(fq/2,L), out;
	for(uint i =0; i < prog.size(); i++) {
		if(prog[i] == 'H') out +='H';
		else out +=prog;
		if(out.length() > s.length()) exit("No\n");}
	if(s != out) cout << "No\n";
	else cout << "Yes\n";
    return 0;}
        
// look at my code
// my code is amazing