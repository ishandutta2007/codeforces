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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	char ch[1000];
	int K;
	scanf(" %s %d",ch,&K);
	string s =(string)ch;
	int N =s.length();

	int ans =min(K,(N+K)/2);
	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) {
		int l =j-i;
		int l2 =min(l,N-j);
		if(j+l > N+K) continue;
		if(s.substr(i,l2) == s.substr(j,l2)) ans =max(ans,l);}
	printf("%d\n",ans*2);
	return 0;}

// look at my code
// my code is amazing