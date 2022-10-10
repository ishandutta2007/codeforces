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
	int N;
	cin >> N;
	vector<int> B(N);
	for(int i =0; i < N; i++) cin >> B[i];
	vector<string> A(N);
	string s ="0";
	for(int i =0; i < N; i++) {
		// spolocny prefix
		for(int p =s.length()-1; p >= 0; p--) {
			if(s[p] == '9') continue;
			int b =B[i];
			for(int j =0; j < p; j++) b -=(s[j]-'0');
			if(b <= 0) continue;
			string s2 =s;
			s2[p] =s[p]+1;
			b -=s2[p]-'0';
			if(b < 0) continue;
			for(int j =s2.length()-1; j > p; j--) {
				s2[j] =(b > 9)?'9':('0'+b);
				b -=s2[j]-'0';}
			if(b > 10) continue;
			if(b > 0) s2[p] +=b;
			if(s2[p] > '9') continue;
			A[i] =s2;
			break;}
		// dalsia cifra
		if(A[i].empty()) {
			// najmensi pocet
			int d =B[i]/9;
			if(B[i]%9 != 0) d++;
			d =max(d,(int)s.length()+1);
			for(int j =0; j < d; j++) A[i] +='0';
			A[i][0]++;
			B[i]--;
			for(int j =d-1; j > 0; j--) {
				A[i][j] +=(B[i] > 9)?9:B[i];
				B[i] -=A[i][j]-'0';}
			A[i][0] +=B[i];}
		s =A[i];}
	for(int i =0; i < N; i++) cout << A[i] << "\n";
	return 0;}

// look at my code
// my code is amazing