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
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 12345678901234567LL
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		set< pair<int,int> > S;
		string s;
		cin >> s;
		for(int a =1; a <= 12; a++) if(12%a == 0) {
			bool b =true;
			for(int i =0; i < 12/a; i++) {
				bool bb =true;
				for(int j =0; j < a; j++) if(s[j*(12/a)+i] == 'O') bb =false;
				if(bb) b =false;}
			if(!b) S.insert(make_pair(a,12/a));}
		cout << S.size();
		ALL_THE(S,it) cout << " " << it->ff << "x" << it->ss;
		cout << "\n";}
	return 0;}

// look at my code
// my code is amazing