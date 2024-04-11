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
#define OVER9000 1234567890123456780LL
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
// mylittlepony
using namespace std;

struct rect {
	int x1,y1,x2,y2;};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<rect> A(N);
	vector< vector<int> > U(3500,vector<int>(3500,10000));
	vector< vector<int> > L(3500,vector<int>(3500,10000));
	vector< vector<int> > R(3500,vector<int>(3500,-1));
	vector< vector<int> > D(3500,vector<int>(3500,-1));
	vector< vector<int> > S(3500,vector<int>(3500,0));
	for(int i =0; i < N; i++) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		A[i].x1 =x1;
		A[i].x2 =x2;
		A[i].y1 =y1;
		A[i].y2 =y2;
		for(int x =x1; x < x2; x++) for(int y =y1; y < y2; y++)
			S[x+1][y+1] =1;
		U[x2][y2] =min(U[x2][y2],x1);
		L[x2][y2] =min(L[x2][y2],y1);
		R[x1][y1] =max(R[x1][y1],y2);
		D[x1][y1] =max(D[x1][y1],x2);}
	for(int i =0; i < 3100; i++) for(int j =0; j < 3100; j++)
		S[i+1][j+1] +=S[i+1][j]+S[i][j+1]-S[i][j];

	for(int i =0; i < 3500; i++) for(int j =0; j < 3500; j++) {
		if(U[i][j] < 10000 && U[U[i][j]][j] < 10000) U[i][j] =U[U[i][j]][j];
		if(L[i][j] < 10000 && L[i][L[i][j]] < 10000) L[i][j] =L[i][L[i][j]];}
	for(int i =3000; i >= 0; i--) for(int j =3000; j >= 0; j--) {
		if(D[i][j] >= 0 && D[D[i][j]][j] >= 0) D[i][j] =D[D[i][j]][j];
		if(R[i][j] >= 0 && R[i][R[i][j]] >= 0) R[i][j] =R[i][R[i][j]];}

	int q =-1, a =-1;
	for(int i =0; i < N; i++) if(q == -1) {
		int ax =D[A[i].x1][A[i].y1]-A[i].x1, ay =R[A[i].x1][A[i].y1]-A[i].y1;
		for(int j =1; j <= min(ax,ay); j++) {
			if(U[A[i].x1+j][A[i].y1+j] > A[i].x1 || L[A[i].x1+j][A[i].y1+j] > A[i].y1) continue;
			if(S[A[i].x1+j][A[i].y1+j]+S[A[i].x1][A[i].y1]-S[A[i].x1][A[i].y1+j]-S[A[i].x1+j][A[i].y1] == j*j)
				q =i, a =j;
			}
		}

	if(q == -1) {cout << "NO\n"; return 0;}
	cout << "YES ";
	vector<int> ans;
	for(int i =0; i < N; i++)
		if(A[i].x2 <= A[q].x1+a && A[i].y2 <= A[q].y1+a && A[i].x1 >= A[q].x1 && A[i].y1 >= A[q].y1)
			ans.push_back(i);
	cout << ans.size() << "\n";
	ALL_THE(ans,it) cout << ((it != ans.begin())?" ":"") << (*it)+1;
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing