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
#define OVER9000 1034567890
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
	cin.tie(0);
	string s;
	int K;
	cin >> s >> K;
	for(int i =0; i < s.length(); i++) {
		char v ='0';
		for(int j =i; j <= min((int)s.length()-1,i+K); j++) v =max(v,s[j]);
		for(int j =i; j < s.length(); j++) if(s[j] == v) {
			for(int k =j; k > i; k--) swap(s[k],s[k-1]);
			K -=(j-i);
			break;}
		}
	cout << s << "\n";
	return 0;}

// look at my code
// my code is amazing