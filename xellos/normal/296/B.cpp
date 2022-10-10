// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	char ch[100000+tisic], ch2[100000+tisic];
	int N;
	scanf(" %d %s %s",&N,ch,ch2);
	string s =(string)ch, w =(string)ch2;
	long long mod =1000000007;

	long long ansP =1, ansN =1, ansX =1, ansEq =1;
	for(int i =0; i < N; i++) {
		if(s[i] == '?' && w[i] == '?') {
			ansP =(ansP*55)%mod;
			ansN =(ansN*55)%mod;
			ansX =(ansX*100)%mod;
			ansEq =(ansEq*10)%mod;}
		else if(s[i] == '?') {
			ansP =(ansP*(w[i]-'0'+1))%mod;
			ansN =(ansN*(10-w[i]+'0'))%mod;
			ansX =(ansX*10)%mod;}
		else if(w[i] == '?') {
			ansN =(ansN*(s[i]-'0'+1))%mod;
			ansP =(ansP*(10-s[i]+'0'))%mod;
			ansX =(ansX*10)%mod;}
		else {
			if(w[i] > s[i]) ansN =ansEq =0;
			if(w[i] < s[i]) ansP =ansEq =0;}
		}

	long long ans =ansX-ansN-ansP+ansEq;
	if(ans < 0) ans +=mod;
	printf("%I64d\n",ans);
	return 0;}

// look at my code
// my code is amazing