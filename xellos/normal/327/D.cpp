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
// mylittlepony
using namespace std;

struct info {
	int F,par;
	bool live;};

struct Move {
	int x,y;
	int type;
	Move() {return;}
	Move(int a, int b, int c) {x =a, y =b, type =c;}};

int R,C;
vector< vector<info> > M(500, vector<info>(500));
vector<Move> ans;
int dx[] ={1,-1,0,0};
int dy[] ={0,0,1,-1};

void DFS(int x, int y) {
	ans.push_back(Move(x,y,0));
	for(int i =0; i < 4; i++) if(x+dx[i] >= 0 && x+dx[i] < R && y+dy[i] >= 0 && y+dy[i] < C) {
		int xn =x+dx[i], yn =y+dy[i];
		if(M[xn][yn].live && M[xn][yn].F == 1) {
			M[xn][yn].live =false;
			M[xn][yn].par =x*C+y;
			DFS(xn,yn);}
		}
	if(M[x][y].par != -1) {
		ans.push_back(Move(x,y,2));
		ans.push_back(Move(x,y,1));}
	}

int main() {
	scanf(" %d %d\n",&R,&C);
	char c;
	for(int i =0; i < R; i++) {for(int j =0; j < C; j++) {
		scanf("%c",&c);
		M[i][j].F =(int)(c == '.');
		M[i][j].par =-1;
		M[i][j].live =true;}
		scanf("%c",&c);}
	
	for(int i =0; i < R; i++) for(int j =0; j < C; j++) 
		if(M[i][j].live && M[i][j].F == 1) {
			M[i][j].live =false;
			DFS(i,j);}
	
	string s ="BRD";
	cout << (int)ans.size() << "\n";
	for(int i =0; i < (int)ans.size(); i++) 
		cout << s[ans[i].type] << " " << ans[i].x+1 << " " << ans[i].y+1 << "\n";
    return 0;}
        
// look at my code
// my code is amazing