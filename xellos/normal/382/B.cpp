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
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int a,b,w,x,c;
	cin >> a >> b >> w >> x >> c;
	if(c <= a) {cout << "0\n"; return 0;}
	if(c-b/x <= a) {
		cout << c-a << "\n";
		return 0;}
	long long k =b/x;
	c -=b/x;
	b =b%x;
	b +=w-x;
	a--; k++; c--;
	if(c <= a) {cout << k << "\n"; return 0;}

	vector<bool> vis(10000,false);
	vis[b] =true;
	while(true) {
		if(c <= a) {cout << k << "\n"; return 0;}
		int bn =(b >= x)?(b-x):(b+w-x);
		k++; c--;
		if(b < x) a--;
		if(c <= a) {cout << k << "\n"; return 0;}
		b =bn;
		if(vis[bn]) break;
		vis[bn] =true;}
	if(c <= a) {cout << k << "\n"; return 0;}

	// zisti cyklus
	for(int i =0; i < 5000; i++) vis[i] =false;
	vis[b] =true;
	int C =0, dA =0;
	while(true) {
		if(c <= a) {cout << k << "\n"; return 0;}
		int bn =(b >= x)?(b-x):(b+w-x);
		k++; c--; C++;
		if(b < x) {a--; dA++;}
		if(c <= a) {cout << k << "\n"; return 0;}
		b =bn;
		if(vis[bn]) break;
		vis[bn] =true;}
	if(c <= a) {cout << k << "\n"; return 0;}

	int rep =(c-a)/(C-dA)-5;
	if(rep > 0) {
		c -=rep*C;
		a -=rep*dA;
		k +=(long long)rep*C;}
	if(c <= a) {cout << k << "\n"; return 0;}
	while(true) {
		int bn =(b >= x)?(b-x):(b+w-x);
		k++; c--;
		if(b < x) a--;
		if(c <= a) {cout << k << "\n"; return 0;}
		b =bn;}
	return 0;}

// look at my code
// my code is amazing