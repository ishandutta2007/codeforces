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
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,P;
	string s;
	cin >> N >> P >> s;
	for(int i =N-1; i >= 0; i--) for(int j =s[i]-'a'+1; j < P; j++) {
		if(i > 0 && j == s[i-1]-'a') continue;
		if(i > 1 && j == s[i-2]-'a') continue;
		string q =s;
		q[i] ='a'+j;
		if(i == N-1) {cout << q << "\n"; return 0;}
		for(int k =i+1; k < N; k++) {
			bool ok =false;
			for(int c =0; c < P; c++) {
				if(k > 0 && c == q[k-1]-'a') continue;
				if(k > 1 && c == q[k-2]-'a') continue;
				ok =true;
				q[k] =c+'a';
				break;}
			if(!ok) break;
			if(k == N-1) {cout << q << "\n"; return 0;}
			}
		}
	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing