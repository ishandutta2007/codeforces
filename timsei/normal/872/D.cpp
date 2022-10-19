#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int N = 5005;

int a[N][N] , pb[N][2] , n , m , all[N] , cnt , P[N] , B[N] , che[N];
bool vis[N][N];

vector<int>G;

int ask(int x , int y) {
	printf("? %d %d\n" , x , y);
	fflush(stdout);
	int p ;
	scanf("%d",&p);
	return p;
}

int get(int x , int y) {
	if(vis[x][y]) return a[x][y];
	int wh = (y - 1 + n) % n; 
	a[x][y] = get(x , wh) ^ a[wh][wh] ^ a[wh][y]; 
	vis[x][y] = 1;
	return a[x][y];
}

void prework(void) {
	for(int i = 0;i < n;i ++) vis[i][i] = 1 , a[i][i] = ask(i , i) , vis[i][(i + 1) % n] = 1 , a[i][(i + 1) % n] = ask(i , (i + 1) % n);
	for(int i = 0;i < n;i ++) {
		for(int j = 0;j < n;j ++) get(i , j);
	}
}

int dance(int x) {
	P[0] = x;
	for(int i = 0;i < n;i ++) B[i] = P[0] ^ a[0][i];
	for(int i = 0;i < n;i ++) P[i] = B[0] ^ a[i][0];
	for(int i = 0;i < n;i ++) if(P[B[i]] != i) return 0;
	if(!G.size()) {
		for(int i = 0;i < n;i ++) G.push_back(P[i]);
	}
	return 1;
}

int main(void) {
	scanf("%d" , &n);
	prework();
	int cnt = 0;
	for(int i = 0;i < n;i ++) cnt += dance(i);
	puts("!");
	printf("%d\n" , cnt);
	for(int i = 0;i <(int) G.size();i ++) printf("%d " , G[i]); 
}