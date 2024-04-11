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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int P[24][24][24];
	for(int i =0; i < 24*24*24; i++) P[i%24][(i/24)%24][i/24/24] =0;
	for(int i =0; i < N; i++) {
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		P[s[0]-'a'][s[1]-'a'][s[2]-'a']++;}

	vector< vector<int> > A(24);
	for(int j =0; j < 24; j++) {
		A[j].resize(1<<j,0);
		// posledne: j
		// predtym len z i
		A[j][0] =P[j][j][j];
		for(int i =1; i < (1<<j); i++)
			for(int k =j-1; k >= 0; k--) if((i>>k)&1) {
				A[j][i] =A[j][i^(1<<k)];
				for(int l =k; l >= 0; l--) if((i>>l)&1)
					A[j][i] +=P[l][k][j];
				A[j][i] +=P[k][j][j];
				break;}
		}

	vector<int> ans(1<<24,0);
	int ansT =0;
	for(int i =1; i < (1<<24); i++)
		for(int j =23; j >= 0; j--) if((i>>j)&1) {
			ans[i] =ans[i^(1<<j)];

			ans[i] +=A[j][(1<<j)-1-(i-(1<<j))]-P[j][j][j];

			for(int k =j-1; k >= 0; k--) if(((i>>k)&1)^1)
				for(int l =j+1; l < 24; l++) ans[i] +=P[k][j][l];
			for(int k =j; k < 24; k++) for(int l =k; l < 24; l++)
				ans[i] +=P[j][k][l];

			ansT ^=ans[i]*ans[i];
			break;}

	cout << ansT << "\n";
	return 0;}

// look at my code
// my code is amazing