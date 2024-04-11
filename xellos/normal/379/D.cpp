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
#define OVER9000 1234567890
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

struct sstr {
	char cf,cs;
	long long occ;};

int main() {
	cin.sync_with_stdio(0);
	int K,X,N,M;
	cin >> K >> X >> N >> M;
	for(int k =0; k < 81; k++) for(int a =0; a < N; a++) for(int b =0; b < M; b++) {
		// s1: A/C/B..A/C/B, s2
		sstr s1,s2;
		s1.cf =k%3+'A';
		s1.cs =(k/3)%3+'A';
		if(s1.cs != s1.cf && N == 1) continue;
		s2.cf =(k/9)%3+'A';
		s2.cs =(k/27)%3+'A';
		if(s2.cs != s2.cf && M == 1) continue;
		s1.occ =a, s2.occ =b;

		vector<sstr> S(K);
		S[0] =s1, S[1] =s2;
		for(int i =2; i < K; i++) {
			S[i].occ =S[i-1].occ+S[i-2].occ;
			if(S[i-1].cf == 'C' && S[i-2].cs == 'A') S[i].occ++;
			S[i].cf =S[i-2].cf;
			S[i].cs =S[i-1].cs;}

		if(S[K-1].occ != X) continue;

		string s1R ="", s2R ="";
		s1R +=s1.cf, s2R +=s2.cf;
		int aR =a, bR =b, n =N-1, m =M-1;
		if(aR > 0 && n > 0 && s1.cf == 'A') {
			s1R +="C";
			aR--;
			n--;}
		for(int i =0; i < n-2*aR-(int)(s1.cs != 'C'); i++) s1R +="B";
		for(int i =0; i < aR; i++) s1R +="AC";
		if(s1.cs != 'C' && N > 1) s1R +=s1.cs;
		if((int)s1R.length() != N) continue;

		if(bR > 0 && m > 0 && s2.cf == 'A') {
			s2R +="C";
			bR--;
			m--;}
		for(int i =0; i < m-2*bR-(int)(s2.cs != 'C'); i++) s2R +="B";
		for(int i =0; i < bR; i++) s2R +="AC";
		if(s2.cs != 'C' && M > 1) s2R +=s2.cs;
		if((int)s2R.length() != M) continue;

//		cout << a << " " << b << " " << s1.cf << " " << s1.cs << " "  << s2.cf << " " << s2.cs << "\n";
		cout << s1R << "\n" << s2R << "\n";
		return 0;}

	cout << "Happy new year!\n";
	return 0;}

// look at my code
// my code is amazing