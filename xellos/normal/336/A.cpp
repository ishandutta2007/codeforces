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
#define OVER9000 234567890
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

int main() {
	int x,y;
	cin >> x >> y;
	int z =abs(x)+abs(y);
	pair<int,int> p =make_pair((x < 0)?(-z):(z),0);
	pair<int,int> r =make_pair(0,(y < 0)?(-z):(z));
	if(p > r) swap(p,r);
	cout << p.ff << " " << p.ss << " " << r.ff << " " << r.ss << "\n";
    return 0;}
        
// look at my code
// my code is amazing