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
	vector<int> P;
	for(int i =0; i < N; i++) if(s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
		P.push_back(i);

/*	pozicia i
	sum 1/|s|
	|s| <= N-i: nedociahnu na koniec
	zacne hocikde po i, skonci pred i
	|s| <= i+1: |s| moznosti
	|s| > i+1: i+1 moznosti
	|s| > N-i: N-i moznosti
	min(N-i,i+1,|s|)
	|s| > i+1,N-i: naraza na obe strany, N-|s|+1
*/
	vector<dbl> H(1000000,0);
	for(int i =1; i <= 600000; i++) H[i] =H[i-1]+1.0/i;

	dbl ans =0;
	ALL_THE(P,it) {
		int x =min(N-*it,*it+1), y =max(*it+1,N-*it);
		ans +=x;
		ans +=(H[y]-H[x])*x;
		ans +=(H[N]-H[y])*(N+1);
		ans -=N-y;}
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;}

// look at my code
// my code is amazing