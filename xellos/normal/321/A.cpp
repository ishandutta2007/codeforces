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
#define patkan 9
#define dibs reserve
#define OVER9000 123456789012345678LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
// mylittlepony
using namespace std;

int main() {
	int a,b;
	string s;
	cin >> a >> b >> s;
	char c[] ={'U','D','L','R'};
	int dx[] ={0,0,-1,1};
	int dy[] ={1,-1,0,0};
	
	vector< pair<int,int> > F(1, make_pair(0,0));
	for(int i =0; i < (int)s.length(); i++) {
		int dir =0;
		for(int j =0; j < 4; j++) if(c[j] == s[i]) dir =j;
		F.push_back(make_pair(F[i].ff+dx[dir],F[i].ss+dy[dir]));}
	int pX =(*F.rbegin()).ff, pY =(*F.rbegin()).ss;
	
	for(int i =0; i < F.size(); i++) {
		int Dx =a-F[i].ff, Dy =b-F[i].ss;
		if(pX == 0 && Dx != 0) continue;
		if(pY == 0 && Dy != 0) continue;
		int A =0, B =0;
		if(pX != 0) A =Dx/pX;
		if(pY != 0) B =Dy/pY;
		if(A < 0 || B < 0) continue;
		if(pX == 0 || pY == 0) A =B =0;
		if(A != B) continue;
		if(Dx%max(1,abs(pX)) == 0 && Dy%max(1,abs(pY)) == 0) {
			cout << "Yes\n";
			return 0;}}
	cout << "No\n";
	return 0;}
        
// look at my code
// my code is amazing