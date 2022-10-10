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
	string s;
	cin >> s;
	int N =s.length();
	for(int i =0; i < N; i++) if((s[i]-'0')%2 == 0 && s[i] < s[N-1]) {
		string ans =s;
		swap(ans[i],ans[N-1]);
		cout << ans << "\n";
		return 0;}
	for(int i =N-1; i >= 0; i--) if((s[i]-'0')%2 == 0 && s[i] > s[N-1]) {
		string ans =s;
		swap(ans[i],ans[N-1]);
		reverse(begin(ans),end(ans));
		while(ans.size() > 1 && *ans.rbegin() == '0') ans.erase(ans.size()-1);
		reverse(begin(ans),end(ans));
		cout << ans << "\n";
		return 0;}
	cout << "-1\n";
	return 0;}

// look at my code
// my code is amazing