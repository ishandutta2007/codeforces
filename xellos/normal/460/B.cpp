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
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a;
	long long b,c;
	cin >> a >> b >> c;
	set<long long> S;
	for(long long s =0; s <= 100; s++) {
		long long x =b;
		for(int i =0; i < a; i++) x *=s;
		x +=c;
		long long y =x, s2 =0;
		while(y > 0) {
			s2 +=y%10;
			y /=10;}
		if(x > 0 && x < 1000000000LL && s2 == s) S.insert(x);}

	cout << S.size() << "\n";
	ALL_THE(S,it) {
		if(it != S.begin()) cout << " ";
		cout << *it;}
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing