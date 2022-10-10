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
#define OVER9000 12345678901234567LL
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
	int N,M;
	cin >> N >> M;
	vector<int> A[20];
	for(int i =0; i < 20; i++) A[i].resize(N);
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		for(int j =0; j < 20; j++) {
			A[j][i] =(int)(a%2 != 0);
			a /=2;}}

	map<int,int> X[20];
	long long ans =0;
	for(int i =0; i < 20; i++) {
		int x =-1;
		for(int j =0; j < N; j++) {
			if(x == -1 && A[i][j]) x =j;
			if(x != -1 && !A[i][j]) {
				X[i][j-1] =x;
				x =-1;}}
		if(x != -1) X[i][N-1] =x;
		ALL_THE(X[i],it) ans +=(1<<i)*1LL*(it->ff-it->ss+1)*1LL*(it->ff-it->ss+2)/2;}

	for(int i =0; i < M; i++) {
		int p,v;
		cin >> p >> v; p--;
		for(int j =0; j < 20; j++) {
			if((int)(v%2 != 0) == A[j][p]) {
				v /=2;
				continue;}
			if(v%2 != 0) {
				auto x =X[j].lower_bound(p);
				A[j][p] =1;
				int a =p, b =p;
				if(x != X[j].begin()) {
					auto y =x; y--;
					if(y->ff == p-1) {
						b =y->ss;
						ans -=(1<<j)*1LL*(y->ff-y->ss+2)*1LL*(y->ff-y->ss+1)/2;
						X[j].erase(y);}}
				if(x != X[j].end())	if(x->ss == p+1) {
					ans -=(1<<j)*1LL*(x->ff-x->ss+2)*1LL*(x->ff-x->ss+1)/2;
					a =x->ff;
					X[j].erase(x);}
				ans +=(1<<j)*1LL*(a-b+1)*1LL*(a-b+2)/2;
				X[j][a] =b;
				v /=2;
				continue;}
			A[j][p] =0;
			auto x =X[j].lower_bound(p);
			ans -=(1<<j)*1LL*(x->ff-x->ss+1)*1LL*(x->ff-x->ss+2)/2;
			ans +=(1<<j)*1LL*(x->ff-p)*1LL*(x->ff-p+1)/2;
			ans +=(1<<j)*1LL*(p-x->ss)*1LL*(p-x->ss+1)/2;
			if(x->ss != p) X[j][p-1] =x->ss;
			if(x->ff != p) X[j][x->ff] =p+1;
			else X[j].erase(x);
			v /=2;}
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing