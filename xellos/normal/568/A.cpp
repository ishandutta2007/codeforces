#include <bits/stdc++.h>
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
#include <time.h>
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
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int p,q;
	cin >> p >> q;
	int mx =2000000;
	vector<bool> isP(mx+tisic,true);
	isP[1] =false;
	long long dif =0;
	vector<int> v;
	int ans =-1;
	for(int i =1; i <= mx; i++) {
		if(isP[i]) dif -=q;
		if(isP[i]) for(int j =1; j <= mx/i; j++) isP[i*j] =false;
		int x =i;
		while(x > 0) {v.push_back(x%10); x /=10;}
		bool is_pal =true;
		for(int i =0; i < v.size()/2; i++) if(v[i] != v[v.size()-1-i]) {is_pal =false; break;}
		v.clear();
		if(is_pal) dif +=p;
		if(dif >= 0) ans =i;}
	if(ans == -1) cout << "Palindromic tree is better than splay tree\n";
	else cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing