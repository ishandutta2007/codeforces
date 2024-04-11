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
	int B,D;
	cin >> B >> D;
	string A,C;
	cin >> A >> C;
	vector<int> pisA(26,0);
	ALL_THE(A,it) pisA[*it-'a']++;
	vector<int> pisC(26,0);
	ALL_THE(C,it) pisC[*it-'a']++;
	for(int i =0; i < 26; i++) if(pisC[i] > 0 && pisA[i] == 0) {
		cout << "0\n";
		return 0;}
	
	vector< pair<int,int> > maxP(max(14242,B+tisic)); // v [a,i] je [c,ff] a najviac c[ss]
	int posA =0;
	for(int i =0; i < 14200; i++) {
		for(int j =0; j < A.length(); j++) 
			if(C[posA%C.length()] == A[j]) posA++;
		maxP[i+1] =make_pair(posA/C.length(),posA%C.length());}
	int Pr =14000;
	while(Pr > 0) {
		if(maxP[14001].ss == maxP[Pr].ss) break;
		Pr--;}
	for(int i =14001; i <= B; i++) {
		maxP[i+1] =maxP[i];
		maxP[i+1].ss =maxP[Pr+1].ss;
		maxP[i+1].ff +=maxP[Pr+1].ff-maxP[Pr].ff;
		Pr++;}
	cout << maxP[B].ff/D << "\n";
	return 0;}
        
// look at my code
// my code is amazing