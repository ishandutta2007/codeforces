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

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> xbh,ybh,xbd,ybd;
	int a =2, ans;
	while(a > 0) {
		int x1 =0, x2 =N;
		while(x2-x1 > 1) {
			cout << "? 1 1 " << (x1+x2)/2 << " " << N << endl;
			cin >> ans;
			if(ans >= a) x2 =(x1+x2)/2;
			else x1 =(x1+x2)/2;}
		xbh.push_back(x2);
		if(x2 == 1) break;
		cout << "? 1 1 " << x2-1 << " " << N << endl;
		cin >> a;}
	if((int)xbh.size() == 1) xbh.push_back(xbh[0]);
	a =2;
	while(a > 0) {
		int x1 =1, x2 =N+1;
		while(x2-x1 > 1) {
			cout << "? " << (x1+x2)/2 << " 1 " << N << " " << N << endl;
			cin >> ans;
			if(ans >= a) x1 =(x1+x2)/2;
			else x2 =(x1+x2)/2;}
		xbd.push_back(x1);
		if(x1 == N) break;
		cout << "? " << x1+1 << " 1 " << N << " " << N << endl;
		cin >> a;}
	if((int)xbd.size() == 1) xbd.push_back(xbd[0]);
	a =2;
	while(a > 0) {
		int x1 =0, x2 =N;
		while(x2-x1 > 1) {
			cout << "? 1 1 " << N << " " << (x1+x2)/2 << endl;
			cin >> ans;
			if(ans >= a) x2 =(x1+x2)/2;
			else x1 =(x1+x2)/2;}
		ybh.push_back(x2);
		if(x2 == 1) break;
		cout << "? 1 1 " << N << " " << x2-1 << endl;
		cin >> a;}
	if((int)ybh.size() == 1) ybh.push_back(ybh[0]);
	a =2;
	while(a > 0) {
		int x1 =1, x2 =N+1;
		while(x2-x1 > 1) {
			cout << "? 1 " << (x1+x2)/2 << " " << N << " " << N << endl;
			cin >> ans;
			if(ans >= a) x1 =(x1+x2)/2;
			else x2 =(x1+x2)/2;}
		ybd.push_back(x1);
		if(x1 == N) break;
		cout << "? 1 " << x1+1 << " " << N << " " << N << endl;
		cin >> a;}
	if((int)ybd.size() == 1) ybd.push_back(ybd[0]);
	
	long long minA =1e15;
	for(int k =0; k < 2; k++) for(int l =0; l < 2; l++) for(int h =0; h < 2; h++) for(int m =0; m < 2; m++) {
		if(xbd[k] > xbh[l] || ybd[h] > ybh[m]) continue;
		cout << "? " << xbd[k] << " " << ybd[h] << " " << xbh[l] << " " << ybh[m] << endl;
		cin >> ans;
		if(ans == 1) minA =min(minA,1LL*(xbh[l]-xbd[k]+1)*(ybh[m]-ybd[h]+1));}
	for(int k =0; k < 2; k++) for(int l =0; l < 2; l++) for(int h =0; h < 2; h++) for(int m =0; m < 2; m++) {
		if(xbd[k] > xbh[l] || ybd[h] > ybh[m]) continue;
		cout << "? " << xbd[k] << " " << ybd[h] << " " << xbh[l] << " " << ybh[m] << endl;
		cin >> ans;
		if(ans == 1 && 1LL*(xbh[l]-xbd[k]+1)*(ybh[m]-ybd[h]+1) == minA) {
			cout << "! " << xbd[k] << " " << ybd[h] << " " << xbh[l] << " " << ybh[m] << " ";
			cout << xbd[1-k] << " " << ybd[1-h] << " " << xbh[1-l] << " " << ybh[1-m] << endl;
			return 0;}
		}

	return 0;}

// look at my code
// my code is amazing