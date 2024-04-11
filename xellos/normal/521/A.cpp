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
	string s;
	cin >> N >> s;
	map<char,int> m;
	for(int i =0; i < N; i++) m[s[i]]++;
	int x =0, y =0;
	ALL_THE(m,it) x =max(x,it->ss);
	ALL_THE(m,it) if(x == it->ss) y++;
	
	long long mod =1000000007, ans =1;
	for(int i =0; i < N; i++) {
		ans =(ans*y)%mod;
		if(ans < 0) ans +=mod;}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing