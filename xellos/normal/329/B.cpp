// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int R,C;
	cin >> R >> C;
	vector<string> map(R);
	vector< vector<bool> > F(R, vector<bool> (C,true));
	pair<int,int> st;
	pair<int,int> en;
	for(int i =0; i < R; i++) {
		cin >> map[i];
		for(int j =0; j < C; j++) {
			if(map[i][j] == 'S') st =make_pair(i,j);
			if(map[i][j] == 'E') en =make_pair(i,j);
			if(map[i][j] == 'T') F[i][j] =false;}}
	int dx[] ={1,-1,0,0};
	int dy[] ={0,0,1,-1};
	
	vector< vector<int> > dist(R, vector<int>(C,OVER9000));
	vector< vector<int> > ako(R, vector<int>(C,-1));
	swap(st,en);
	dist[st.ff][st.ss] =C*st.ff+st.ss;
	queue< pair<int,int> > q;
	q.push(st);
	while(!q.empty()) {
		pair<int,int> p =q.front();
		for(int i =0; i < 4; i++) if(sent(p.ff+dx[i],p.ss+dy[i]))
			if(ako[p.ff+dx[i]][p.ss+dy[i]] == -1 && F[p.ff+dx[i]][p.ss+dy[i]]) {
				ako[p.ff+dx[i]][p.ss+dy[i]] =p.ff*C+p.ss;
				dist[p.ff+dx[i]][p.ss+dy[i]] =dist[p.ff][p.ss]+1;
				q.push(make_pair(p.ff+dx[i],p.ss+dy[i]));}
		q.pop();}
	
	int ans =0;
	for(int i =0; i < R; i++) for(int j =0; j < C; j++) 
		if(dist[i][j] <= dist[en.ff][en.ss] && map[i][j] >= '0' && map[i][j] <= '9') ans +=(int)(map[i][j]-'0');
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing