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
#define OVER9000 223456789012345678LL
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

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	return (x == 0)?y:gcd(y%x,x);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int A,B;
	cin >> A >> B;
	if(A > B) swap(A,B);
	int d =gcd(A,B);
	vector< pair<int,int> > pytA;
	for(int a =1; a < A; a++) for(int i =1; i < A; i++)
		if(i*i+a*a == A*A && i%(A/d) == 0 && i != (B/d)*(a/(A/d))) {
			cout << "YES\n0 0\n";
			cout << a << " " << i << "\n";
			cout << -(B/d)*(i/(A/d)) << " " << (B/d)*(a/(A/d)) << "\n";
			return 0;}
	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing