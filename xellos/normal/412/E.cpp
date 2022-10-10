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
#define OVER9000 2234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
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
	string s;
	cin >> s;
	int N =s.length();
	vector<int> st(N,0),fin(N,0);

	for(int i =0; i < N; i++) if(s[i] == '@') {
		int j =i-1, l =0;
		while(j >= 0 && ((s[j] >= 'a' && s[j] <= 'z') || s[j] == '_' || (s[j] >= '0' && s[j] <= '9'))) {
			if(j >= 0 && (s[j] >= 'a' && s[j] <= 'z')) l++;
			j--;}
		st[i] =l;}

	for(int i =0; i < N; i++) if(s[i] == '.') {
		int j =i+1;
		while(j < N && (s[j] >= 'a' && s[j] <= 'z')) j++;
		fin[i] =j-i-1;}

	long long ans =0;
	for(int i =0; i < N; i++) if(s[i] == '@') {
		int j =i+1;
		while(j < N && ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) j++;
		if(j == i+1 || j == N) continue;
		if(s[j] != '.') continue;
		ans +=1LL*st[i]*fin[j];}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing