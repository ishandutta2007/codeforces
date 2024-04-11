#include <bits/stdc++.h>
using namespace std;

int main() {
int R,C,E =0,cc =0;
cin >> R >> C;
vector<string> V(R);
for(int i =0; i < R; i++) cin >> V[i];
for(int i =0; i < R; i++) for(int j =0; j < C-1; j++)
if(V[i][j] == V[i][j+1]) E++;
for(int i =0; i < R-1; i++) for(int j =0; j < C; j++)
if(V[i][j] == V[i+1][j]) E++;
vector< vector<bool> > vis(R,vector<bool>(C,false));
int dx[] ={1,-1,0,0};
int dy[] ={0,0,1,-1};
for(int i =0; i < R; i++) for(int j =0; j < C; j++) if(!vis[i][j]) {
queue< pair<int,int> > q;
q.push(make_pair(i,j));
vis[i][j] =true;
while(!q.empty()) {
int x =q.front().first, y =q.front().second;
for(int k =0; k < 4; k++) if(x+dx[k] >= 0 && y+dy[k] >= 0 && x+dx[k] < R && y+dy[k] < C) if(!vis[x+dx[k]][y+dy[k]] && V[x][y] == V[x+dx[k]][y+dy[k]]) {
vis[x+dx[k]][y+dy[k]] =true;
q.push(make_pair(x+dx[k],y+dy[k]));}
q.pop();}
cc++;}
if(E == R*C-cc) cout << "No\n";
else cout << "Yes\n";}