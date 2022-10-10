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
#define OVER9000 1234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	string S[2];
	cin >> N >> M >> S[0] >> S[1];
	vector<int> last(N,-1),next(N,N+1),P(N,0);
	for(int i =0; i < N; i++)
		if(S[0][i] == 'X' || S[1][i] == 'X') last[i] =next[i] =i;
	for(int i =1; i < N; i++) last[i] =max(last[i],last[i-1]);
	for(int i =N-2; i >= 0; i--) next[i] =min(next[i],next[i+1]);

	int l =0;
	for(int i =0; i < N; i++) if(S[1-l][i] == 'X') {
		l =1-l;
		P[i]++;}
	for(int i =1; i < N; i++) P[i] +=P[i-1];

	vector<int> isC(2*N,-1);
	queue< pair<int,int> > q;
	int cc =0;
	for(int i =0; i < N; i++) for(int j =0; j < 2; j++) if(isC[j*N+i] == -1 && S[j][i] == '.') {
		q.push(make_pair(i,j));
		isC[j*N+i] =cc;
		while(!q.empty()) {
			if(isC[(1-q.front().ss)*N+q.front().ff] == -1 && S[1-q.front().ss][q.front().ff] == '.') {
				isC[(1-q.front().ss)*N+q.front().ff] =cc;
				q.push(make_pair(q.front().ff,1-q.front().ss));}
			if(q.front().ff < N-1)
			if(isC[q.front().ss*N+q.front().ff+1] == -1 && S[q.front().ss][q.front().ff+1] == '.') {
				isC[q.front().ss*N+q.front().ff+1] =cc;
				q.push(make_pair(q.front().ff+1,q.front().ss));}
			q.pop();}
		cc++;}

	for(int i =0; i < M; i++) {
		int a,b,x1,y1,x2,y2;
		cin >> a >> b;
		a--, b--;
		if(isC[a] != isC[b]) {cout << "-1\n"; continue;}
		x1 =a%N, y1 =a/N;
		x2 =b%N, y2 =b/N;
		if(x1 > x2) {swap(x1,x2); swap(y1,y2);}
		if(last[x2] <= x1) {
			cout << x2-x1+abs(y1-y2) << "\n";
			continue;}
		int ans =x2-x1;
		x1 =next[x1];
		x2 =last[x2];
		if(S[y1][x1] == 'X') {ans++; y1 =1-y1;}
		if(S[y2][x2] == 'X') {ans++; y2 =1-y2;}
		ans +=P[x2]-P[x1];
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing